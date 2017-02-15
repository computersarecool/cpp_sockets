#pragma once
#include "base_socket.h"

class UDPClient : public Socket 
{
public:
  UDPClient::UDPClient(const std::string& ip_address = "127.0.0.1", int port = 8000);
  int send_message(const std::string& message);
};

