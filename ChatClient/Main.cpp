#include <thread>
#include <mutex>

#include "UI/UI.h"
#include "IO/ConfigManager.h"
#include "Net/ChatClient.h"
#include "Util/Time.h"
#include "Net/ChatClient.h"

using std::thread;
using std::mutex;

ConfigManager* initConfigFile();
Client* initClient();

UI* ui = new UI();
ConfigManager* config;
Client* client;

ConfigManager* initConfigFile() {
	ConfigManager* config = new ConfigManager();

	return config;
}



Client* initClient() {
	ConfigFile* file = config->getConfigFile();
	return new Client(
		file->getValue(file->IP_),
		stoi(file->getValue(file->PORT_))
	);
}

void closeClient(){
	delete ui;
	ui = nullptr;
}

int main() {
	config = initConfigFile();
	do {



		client = initClient();
		ConfigFile* file = config->getConfigFile();
		Content::max_width = stoi(file->getValue(ConfigFile::MAX_WIDTH_));
		client->start(
			file->getValue(file->NAME_),
			file->getValue(file->PASSWD_)
		);
		//获取用户名
		string username = file->getValue(ConfigFile::NAME_);
		//若密码正确，则保持连接并允许接收消息，否则断开连接，提示密码错误
		if (!client->isReady()) {
			log("Connect failed, probably because of the wrong passwd, or a network error, or... maybe just you and your server are not in the same network");
			return -1;
		}
		log("Connect Success");
		//获取服务器名称
		if (username == "anonymity") {
			log("\nPlease input your name: ", false);
			string name;
			std::getline(cin, name);
			username = name;
			file->setValue(ConfigFile::NAME_, username);
			config->saveConfigFile();
		}

		//开始显示主画面，并进行通信
		ui->start(string("welcome to the " + client->getServerName() + ", " + username));
		thread([=]() {
			while (client->isReady()) {
				char* buffer = new char[0xffff];
				int buffer_size = recv(client->getSocketFD(), buffer, 0xffff, 0);
				buffer[buffer_size] = '\0';
				if (buffer_size == -1) {
					string line = client->getServerName() + " is closed, please input any key...";
					ui->refresh(Message(line, Color(Color::Code::Green), Msg::Align::Right));
					client->restart();
					break;
				}
				string line = buffer;
				ui->refresh("\n");
				ui->refresh(Message(line, Color(Color::Code::Green), Msg::Align::Right));
				ui->refresh(Msg("^ " + string(generateTime()) + " ^", Msg::Align::Center));
				ui->refresh("");
				Input::prompt(username);
			}
			}).detach();

			while (client->isReady()) {

				Input input(username);
				ui->refresh(Msg("^ " + string(generateTime()) + " ^", Msg::Align::Center));
				ui->refresh(Message::generateCharLine());

				string buffer = input();
				send(client->getSocketFD(), buffer.c_str(), buffer.size(), 0);

			}



	} while (1);
	closeClient();
	return 0;
}