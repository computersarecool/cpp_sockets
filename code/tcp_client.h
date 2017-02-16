#pragma once
#include "base_socket.h"

class TCPClient : public Socket 
{
public:
	TCPClient(int port = 8000, const std::string& ip_address = "127.0.0.1");
	int make_connection();
	int send_message(const std::string& message);
	void close();
};
