#pragma once
#include "base_socket.h"

// UDP Client
class TCPServer : public Socket {
public:
    TCPServer::UDPClient(SocketType socket_type = SocketType::TYPE_STREAM, const std::string& ip_address = "127.0.0.1", int port = 8000);

};

