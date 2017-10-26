#pragma once

#include "project/base_socket.h"

class UDPClient : public Socket 
{
public:
  UDPClient(u_short port = 8000, const std::string& ip_address = "127.0.0.1");
  int send_message(const std::string& message);
};

