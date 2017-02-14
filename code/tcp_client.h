#pragma once
#include "base_socket.h"

// TCP Client
class TCPClient : public Socket 
{
public:
	TCPClient(const SocketType socket_type = SocketType::TYPE_STREAM, const std::string& ip_address = "127.0.0.1", const int& port = 8000);
	int make_connection();
	int send_message(const std::string& message);
	void close();
};

