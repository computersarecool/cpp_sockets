#pragma once
#include "base_socket.h"

// UDP Server
class UDPServer : public Socket 
{
public:
    UDPServer(const SocketType socket_type = SocketType::TYPE_DGRAM, const std::string& ip_address = "127.0.0.1", const int& port = 8000);
    void socket_bind();
    void listen();
};
