#pragma once
#include "project/base_socket.h"

class TCPServer : public Socket
{
public:
	TCPServer(int port, const std::string& ip_address = "0.0.0.0");
	void socket_bind();
};
