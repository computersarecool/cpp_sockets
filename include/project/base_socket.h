#pragma once

#include <string>
#include <iostream>

// Windows
#if defined(_WIN32)
  #define _WINSOCK_DEPRECATED_NO_WARNINGS
  #include<winsock2.h>
  #include <Ws2tcpip.h>
  #pragma comment(lib, "ws2_32.lib")
  #define socklen_t int

// Linux
#else
  #include<sys/socket.h>
  #include<arpa/inet.h> // This contains inet_addr
  #include <unistd.h> //This contains close
  #define INVALID_SOCKET (SOCKET)(~0)
  #define SOCKET_ERROR (-1)
  #define closesocket close
  typedef int SOCKET;
#endif

class Socket {
public:
  enum class SocketType {
    TYPE_STREAM = SOCK_STREAM,
    TYPE_DGRAM = SOCK_DGRAM
  };

protected:
    Socket(const SocketType socket_type);
    ~Socket();
    SOCKET m_socket;
    sockaddr_in m_addr;
    void set_port(u_short port);
    int get_port();
    int set_address(const std::string& ip_address);
    std::string get_address();

private:
  static int s_count;
};
