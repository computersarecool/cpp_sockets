#include "project/base_socket.h"

// Initialize the count of sockets (track this to call WSACleanup on Windows)
int Socket::s_count = 0;

Socket::Socket(const SocketType socket_type)
{
#ifdef WIN32
  // Initialize the WSDATA if no socket instances exist
  if(!s_count)
  {
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
      throw std::runtime_error("Error initializing Winsock " + WSAGetLastError());
    }
  }
#endif

  // Create the socket handle
  m_socket = socket(AF_INET, static_cast<int>(socket_type), 0);
  if (m_socket == INVALID_SOCKET)
  {
    throw std::runtime_error("Could not create socket");
  }

  std::cout << "Socket created." << std::endl;

  m_addr.sin_family = AF_INET;

#ifdef WIN32
  ++s_count;
#endif
}

void Socket::set_port(u_short port)
{
  m_addr.sin_port = htons(port);
}

int Socket::get_port()
{
  return ntohs(m_addr.sin_port);
}

int Socket::set_address(const std::string& ip_address)
{
  return inet_pton(AF_INET, ip_address.c_str(), &m_addr.sin_addr);
}

std::string Socket::get_address()
{
  return std::string (inet_ntoa(m_addr.sin_addr));
}

Socket::~Socket()
{
#ifdef WIN32
  --s_count;
  if(!s_count)
  {
    WSACleanup();
  }
#endif
}
