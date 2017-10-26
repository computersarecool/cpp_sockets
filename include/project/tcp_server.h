#pragma once

#include "project/base_socket.h"

class TCPServer : public Socket
{
public:
	TCPServer(u_short port, const std::string& ip_address = "0.0.0.0");
	void socket_bind();
};
