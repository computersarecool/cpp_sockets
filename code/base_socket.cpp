#include "base_socket.h"

// Initialize the s_count (tracking for Windows to call WSASetup)
int Socket::s_count = 0;

// Socket constructor
Socket::Socket(SocketType t_SocketType)
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
  ++s_count;
#endif

  // Create the actual socket
  m_socket = socket(AF_INET, static_cast<int>(t_SocketType), 0);
  if (m_socket == INVALID_SOCKET)
  {
    throw std::runtime_error("Could not create socket");
  }

  std::cout << "Socket created." << std::endl;

  m_addr.sin_family = AF_INET;
}

// Socket set port
void Socket::set_port(int t_port)
{
  m_addr.sin_port = htons(t_port);
}

// Socket get port
int Socket::get_port()
{
  return ntohs(m_addr.sin_port);
}

// Socket set address
int Socket::set_address(const std::string& t_ip_address)
{
  return inet_pton(AF_INET, t_ip_address.c_str(), &m_addr.sin_addr);
}

// Socket get address
std::string Socket::get_address()
{
  std::string ip_address(inet_ntoa(m_addr.sin_addr));
  return  ip_address;
}

// Socket Destructor
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

