#include "udp_client.h"

UDPClient::UDPClient(int port, const std::string& ip_address) : Socket(SocketType::TYPE_DGRAM)
{
  set_address(ip_address);
  set_port(port);
  std::cout << "UDP Client created." << std::endl;
};

// Send message
int UDPClient::send_message(const std::string& message)
{
  return sendto(m_socket, message.c_str(), message.length(), 0, reinterpret_cast<sockaddr*>(&m_addr), sizeof(m_addr));
};
