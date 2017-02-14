#pragma once
#include "base_socket.h"

// UDP Client
class UDPClient : public Socket 
{
public:
  UDPClient::UDPClient(const SocketType socket_type = SocketType::TYPE_DGRAM, const std::string& ip_address = "127.0.0.1", const int& port = 8000);
  int send_message(const std::string& message);
};

