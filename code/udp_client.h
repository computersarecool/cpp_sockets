#pragma once
#include "base_socket.h"

// UDP Client
class UDPClient : public Socket {
public:
  UDPClient::UDPClient(SocketType t_SocketType = TYPE_DGRAM, const std::string& t_ip_address = "127.0.0.1", int t_port = 8000);
  int send_message(const std::string& message);
};

