#ifndef H_CHATCLIENT
#define H_CHATCLIENT

#include <set>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "../Util/Log.h"

#pragma comment(lib,"Ws2_32.lib")
using namespace std;

class Client {
	WSADATA wsadata;

	SOCKET server_socket;
	sockaddr_in target_addr;

	bool ready = false;
	string ip;
	string server_name;
	void makeAddr(const string& ip, const int& port);
	void initSocket();
public:
	Client(const string& ip, const int& port);
	~Client();
	void start(const string& usename, const string& passwd);

	const SOCKET& getSocketFD() const;
	const string& getServerName() const;
	const bool& isReady() const;
	void restart();
};

#endif