#pragma once
#include "base_socket.h"

// UDP Server
class UDPServer : public Socket {
public:
  UDPServer(SocketType t_SocketType = TYPE_DGRAM, const std::string& t_ip_address = "127.0.0.1", int t_port = 8000);
  void socket_bind();
  void listen();
};
