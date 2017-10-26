#pragma once

#include "project/base_socket.h"

class UDPServer : public Socket 
{
public:
    UDPServer(u_short port = 8000, const std::string& ip_address = "0.0.0.0");
    void socket_bind();
    void listen();
};
