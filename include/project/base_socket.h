#pragma once

#include <string>
#include <iostream>

// For windows
#if defined(_WIN32)
  #include<winsock2.h>
  #include <Ws2tcpip.h>
  #pragma comment(lib, "ws2_32.lib")
  #define socklen_t int

// For Linux
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
    void set_port(int port);
    int get_port();
    int set_address(const std::string& ip_address);
    std::string get_address();

private:
  static int s_count;
};
