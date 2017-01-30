#include "udp_server.h"

// UDP Server Constructor
// TODO: Move socket_bind to its own method
UDPServer::UDPServer(SocketType t_SocketType, const std::string& t_ip_address, int t_port) : Socket(t_SocketType)
{
  set_port(t_port);
  set_address(t_ip_address);
  std::cout << "UDP Server created." << std::endl;
  socket_bind();
}

// UDP Server bind
void UDPServer::socket_bind()
{
  if (bind(m_socket, (struct sockaddr*)&m_addr, sizeof(m_addr)) == SOCKET_ERROR)
  {
    std::cout << "UDP Bind error." << std::endl;
#ifdef WIN32
    std::cout << WSAGetLastError() << std::endl;
#endif
  }
  std::cout << "UDP Socket Bound." << std::endl;
}

// UDP Server listen
// TODO: Get information from peer
// TODO: Typecast char buf to unsigned char buf
void UDPServer::listen()
{
  while(true)
  {
    char buf[512];
    sockaddr_in client;
    int slen = sizeof(client);
    int recv_len = recvfrom(m_socket, buf, sizeof(buf), 0, (sockaddr*)&client, &slen);
    if (recv_len == SOCKET_ERROR)
    {
      std::cout << "UDP Bind error." << std::endl;
#ifdef WIN32
      std::cout << WSAGetLastError() << std::endl;
#endif
    }
    std::cout << "Incoming Data:" << std::endl;
	std::cout << buf << std::endl;
  }
}

