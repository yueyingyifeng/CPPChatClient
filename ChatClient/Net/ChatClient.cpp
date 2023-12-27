#include "ChatClient.h"


void Client::makeAddr(const string& ip, const int& port)
{
	this->ip = ip;
	target_addr.sin_family = AF_INET;
	target_addr.sin_port = htons(port);
	inet_pton(AF_INET, ip.c_str(), &target_addr.sin_addr);
}

void Client::initSocket()
{
	if (WSAStartup(MAKEWORD(2, 2), &this->wsadata) != 0) {

		elog("WSAstartup failed");
	}
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
}

Client::Client(const string& ip, const int& port)
{
	initSocket();
	makeAddr(ip,port);

	ready = true;
}

Client::~Client()
{



	WSACleanup();
	closesocket(server_socket);
}

void Client::start(const string& usename, const string& passwd)
{
	if (!ready) return;
	bool isFailed = false;
	do {
		if (connect(server_socket, (sockaddr*)&target_addr, sizeof(target_addr)) == -1) {
			if(!isFailed)
				log("Connecting to the server: " + ip + "  ", false);
			log(".", false);
			isFailed = true;
		}
		else
			isFailed = false;
	} while (isFailed);

	

	string buffer = usename + " " + passwd;

	send(server_socket, buffer.c_str(), buffer.size(), 0);

	char* buff = new char[0xffff];
	int b_size = recv(server_socket, buff, 0xffff, 0);
	buff[b_size] = '\0';
	if (strcmp(buff,"0") == 0)
		ready = false;
	server_name = buff;

	delete buff;
	buff = nullptr;
}

const SOCKET& Client::getSocketFD() const
{
	return server_socket;
}

const string& Client::getServerName() const
{
	return server_name;
}

const bool& Client::isReady() const
{
	return ready;
}

void Client::restart()
{
	ready = false;
}

