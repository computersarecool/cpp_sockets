#include "project/udp_client.h"

UDPClient::UDPClient(u_short port, const std::string& ip_address) : Socket(SocketType::TYPE_DGRAM)
{
  set_address(ip_address);
  set_port(port);
  std::cout << "UDP Client created." << std::endl;
};

// Send message
int UDPClient::send_message(const std::string& message)
{
  int message_length = static_cast<int>(message.length());
  return sendto(m_socket, message.c_str(), message_length, 0, reinterpret_cast<sockaddr*>(&m_addr), sizeof(m_addr));
};
