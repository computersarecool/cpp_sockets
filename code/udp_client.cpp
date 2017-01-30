#include "udp_client.h"

// UDP Client Constructor
UDPClient::UDPClient(SocketType t_SocketType, const std::string& t_ip_address, int t_port) : Socket(t_SocketType)
{
  set_port(t_port);
  set_address(t_ip_address);
  std::cout << "UDP Client created." << std::endl;
};


// UDP Client Send message
int UDPClient::send_message(const std::string& message)
{
  return sendto(m_socket, message.c_str(), message.length(), 0, (sockaddr*)&m_addr, sizeof(m_addr));
};
