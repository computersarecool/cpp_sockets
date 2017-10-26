#pragma once

#include "project/base_socket.h"

class TCPClient : public Socket 
{
public:
	TCPClient(u_short port = 8000, const std::string& ip_address = "127.0.0.1");
	int make_connection();
	int send_message(const std::string& message);
	void close();
};

