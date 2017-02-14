#include "udp_client.h"

// UDP Client Constructor
UDPClient::UDPClient(const SocketType socket_type, const std::string& ip_address, const int& port) : Socket(socket_type)
{
  set_port(port);
  set_address(ip_address);
  std::cout << "UDP Client created." << std::endl;
};


// UDP Client Send message
int UDPClient::send_message(const std::string& message)
{
  return sendto(m_socket, message.c_str(), message.length(), 0, reinterpret_cast<sockaddr*>(&m_addr), sizeof(m_addr));
};
