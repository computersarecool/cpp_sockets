#pragma once
#include "base_socket.h"

class UDPClient : public Socket 
{
public:
  UDPClient::UDPClient(int port = 8000, const std::string& ip_address = "127.0.0.1");
  int send_message(const std::string& message);
};

