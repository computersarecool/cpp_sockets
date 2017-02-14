#pragma once
#include "base_socket.h"

class TCPServer : public Socket
{
public:
	TCPServer(const SocketType socket_type = SocketType::TYPE_STREAM, const std::string& ip_address = "127.0.0.1", const int& port = 8000);
	void socket_bind();
};