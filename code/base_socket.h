#pragma once
#include <string>
#include <iostream>

#if defined(WIN32)
  #include<winsock2.h>
  #include <Ws2tcpip.h>
  #pragma comment(lib, "ws2_32.lib")
  #define socklen_t int
#else
  #include<sys/socket.h>
  #include<arpa/inet.h> //inet_addr
  #include <unistd.h> //close
  typedef int SOCKET;
  #define INVALID_SOCKET (SOCKET)(~0)
  #define SOCKET_ERROR (-1)
  #define closesocket close
#endif


class Socket {
public:
  enum SocketType {
    TYPE_STREAM = SOCK_STREAM,
    TYPE_DGRAM = SOCK_DGRAM,
    TYPE_RAW = SOCK_RAW
  };
  ~Socket();

protected:
  Socket(SocketType t_SocketType);
  SOCKET m_socket;
  sockaddr_in m_addr;
  void set_port(int t_port);
  int get_port();
  int set_address(const std::string& t_ip_address);
  std::string get_address();

private:
  static int s_count;
};
