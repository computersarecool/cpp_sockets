#pragma once
#include "base_socket.h"

class UDPServer : public Socket 
{
public:
    UDPServer(int port = 8000, const std::string& ip_address = "0.0.0.0");
    void socket_bind();
    void listen();
};
