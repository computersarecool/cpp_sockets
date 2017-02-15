#include "udp_client.h"

// Constructor
UDPClient::UDPClient(const std::string& ip_address, int port) : Socket(SocketType::TYPE_DGRAM)
{
  set_port(port);
  set_address(ip_address);
  std::cout << "UDP Client created." << std::endl;
};

// UDP Send message
int UDPClient::send_message(const std::string& message)
{
  return sendto(m_socket, message.c_str(), message.length(), 0, reinterpret_cast<sockaddr*>(&m_addr), sizeof(m_addr));
};
