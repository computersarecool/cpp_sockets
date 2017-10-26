#include "project/udp_server.h"

// UDP Server Constructor
UDPServer::UDPServer(u_short port, const std::string& ip_address) : Socket(SocketType::TYPE_DGRAM)
{
  set_port(port);
  set_address(ip_address);
  std::cout << "UDP Server created." << std::endl;
}

// UDP Server bind
void UDPServer::socket_bind()
{
  if (bind(m_socket, reinterpret_cast<sockaddr*>(&m_addr), sizeof(m_addr)) == SOCKET_ERROR)
  {
    std::cout << "UDP Bind error." << std::endl;
#ifdef WIN32
    std::cout << WSAGetLastError() << std::endl;
#endif
  }
  std::cout << "UDP Socket Bound." << std::endl;
}

// UDP Server listen
void UDPServer::listen()
{
  while(true)
    {
        sockaddr_in client;
        char client_ip[INET_ADDRSTRLEN];
        socklen_t slen = sizeof(client);
        char message_buffer[512];
        std::cout << "Waiting for data..." << std::endl;
		
        // This is a blocking call
        int recv_len = recvfrom(m_socket, message_buffer, sizeof(message_buffer), 0, reinterpret_cast<sockaddr*>(&client), &slen);
        if (recv_len == SOCKET_ERROR)
        {
          std::cout << "Receive Data error." << std::endl;
    #ifdef WIN32
          std::cout << WSAGetLastError() << std::endl;
    #endif
        }
        std::cout << "Received packet from " << inet_ntop(AF_INET, &client.sin_addr, client_ip, INET_ADDRSTRLEN) << ':' << ntohs(client.sin_port) << std::endl;
	    std::cout << message_buffer << std::endl;
    }
}

