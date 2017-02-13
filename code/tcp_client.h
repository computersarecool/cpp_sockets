#pragma once
#include "base_socket.h"

// TCP Server
class TCPClient : public Socket 
{
public:
	TCPClient(SocketType socket_type = SocketType::TYPE_STREAM, const std::string& ip_address = "127.0.0.1", int port = 8000);
	int make_connection();
	int send_message(std::string message);
	void close();
};

