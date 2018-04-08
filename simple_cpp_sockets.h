// Possible errors:
// 1 Invalid protocol
// 2 Invalid socket type
// 3 Socket bind error
// 4 Socket accept error
// 5 Connection error
// 6 Message send error
// 7 Receive error

#include <string>
#include <iostream>

// Windows
#if defined(_WIN32)
#define _WINSOCK_DEPRECATED_NO_WARNINGS
  #include<winsock2.h>
  #include <Ws2tcpip.h>
  #pragma comment(lib, "ws2_32.lib")
  typedef SSIZE_T ssize_t;

  // Linux
#else
#include <sys/socket.h>
#include <arpa/inet.h> // This contains inet_addr
#include <unistd.h> // This contains close
#define INVALID_SOCKET (SOCKET)(~0)
#define SOCKET_ERROR (-1)
typedef int SOCKET;
#endif

// Interfaces
class Socket {
public:
    enum class SocketType {
        TYPE_STREAM = SOCK_STREAM,
        TYPE_DGRAM = SOCK_DGRAM
    };

protected:
    explicit Socket(SocketType socket_type);
    ~Socket();
    SOCKET m_socket;
    sockaddr_in m_addr;
    void set_port(u_short port);
    int set_address(const std::string& ip_address);

private:
#ifdef WIN32
    // Number of sockets is tracked to call WSACleanup on Windows
	static int s_count;
#endif
};

#ifdef WIN32
// Number of sockets is tracked to call WSACleanup on Windows
int Socket::s_count{ 0 };
#endif

class UDPClient : public Socket
{
public:
    UDPClient(u_short port = 8000, const std::string& ip_address = "127.0.0.1");
    ssize_t send_message(const std::string& message);
};

class UDPServer : public Socket
{
public:
    UDPServer(u_short port = 8000, const std::string& ip_address = "0.0.0.0");
    int socket_bind();
    void listen();
};

class TCPClient : public Socket
{
public:
    TCPClient(u_short port = 8000, const std::string& ip_address = "127.0.0.1");
    int make_connection();
    int send_message(const std::string& message);
};

class TCPServer : public Socket
{
public:
    TCPServer(u_short port, const std::string& ip_address = "0.0.0.0");
    int socket_bind();
};

// Implementations
Socket::Socket(const SocketType socket_type) : m_socket(), m_addr()
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

    m_addr.sin_family = AF_INET;

#ifdef WIN32
    ++s_count;
#endif
}

void Socket::set_port(u_short port)
{
    m_addr.sin_port = htons(port);
}

int Socket::set_address(const std::string& ip_address)
{
    return inet_pton(AF_INET, ip_address.c_str(), &m_addr.sin_addr);
}

#ifdef WIN32
Socket::~Socket()
{
  if(! --s_count)
  {
    WSACleanup();
  }
}
#else
Socket::~Socket() = default;
#endif


UDPClient::UDPClient(u_short port, const std::string& ip_address) : Socket(SocketType::TYPE_DGRAM)
{
    set_address(ip_address);
    set_port(port);
    std::cout << "UDP Client created." << std::endl;
};

ssize_t UDPClient::send_message(const std::string& message)
{
    size_t message_length = message.length();
    return sendto(m_socket, message.c_str(), message_length, 0, reinterpret_cast<sockaddr*>(&m_addr), sizeof(m_addr));
};

UDPServer::UDPServer(u_short port, const std::string& ip_address) : Socket(SocketType::TYPE_DGRAM)
{
    set_port(port);
    set_address(ip_address);
    std::cout << "UDP Server created." << std::endl;
}

int UDPServer::socket_bind()
{
    if (bind(m_socket, reinterpret_cast<sockaddr*>(&m_addr), sizeof(m_addr)) == SOCKET_ERROR)
    {
        std::cout << "UDP Bind error." << std::endl;
#ifdef WIN32
        std::cout << WSAGetLastError() << std::endl;
#endif
        return 3;
    }
    std::cout << "UDP Socket Bound." << std::endl;
    return 0;
}

void UDPServer::listen()
{
    sockaddr_in client;
    char client_ip[INET_ADDRSTRLEN];
    socklen_t slen = sizeof(client);
    char message_buffer[512];
    std::cout << "Waiting for data..." << std::endl;

    while(true)
    {
        // This is a blocking call
        ssize_t recv_len = recvfrom(m_socket, message_buffer, sizeof(message_buffer), 0, reinterpret_cast<sockaddr*>(&client), &slen);
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

TCPClient::TCPClient(u_short port, const std::string& ip_address) : Socket(SocketType::TYPE_STREAM)
{
    set_address(ip_address);
    set_port(port);
    std::cout << "TCP client created." << std::endl;
}

int TCPClient::make_connection()
{
    std::cout << "Connecting" << std::endl;
    if (connect(m_socket, reinterpret_cast<sockaddr*>(&m_addr), sizeof(m_addr)) < 0)
    {
        std::cout << "Connection error" << std::endl;
        return 5;
    }
    std::cout << "connected" << std::endl;
    return 0;
}

int TCPClient::send_message(const std::string& message)
{
    char server_reply[2000];
    size_t length = message.length();

    if (send(m_socket, message.c_str(), length, 0) < 0)
    {
        std::cout << "Send failed" << std::endl;
        return 6;
    }
    else
    {
        std::cout << "Data sent" << std::endl;
    }

    if (recv(m_socket, server_reply, 2000, 0) == SOCKET_ERROR)
    {
        std::cout << "Receive Failed" << std::endl;
        return 7;
    }
    else
    {
        std::cout << server_reply << std::endl;
    }

    return 0;
}

TCPServer::TCPServer(u_short port, const std::string& ip_address) : Socket(SocketType::TYPE_STREAM)
{
    set_port(port);
    set_address(ip_address);
    std::cout << "TCP Server created." << std::endl;
};

int TCPServer::socket_bind()
{
    if (bind(m_socket, reinterpret_cast<sockaddr*>(&m_addr), sizeof(m_addr)) == SOCKET_ERROR)
    {
        std::cout << "TCP Socket Bind error." << std::endl;
#ifdef WIN32
        std::cout << WSAGetLastError() << std::endl;
#endif
        return 3;
    }

    std::cout << "TCP Socket Bound." << std::endl;
    listen(m_socket, 3);
    std::cout << "TCP Socket waiting for incoming connections..." << std::endl;

    socklen_t client_size = sizeof(sockaddr_in);
    sockaddr_in client;
    SOCKET new_socket;
    char message_buffer[512];

    new_socket = accept(m_socket, reinterpret_cast<sockaddr*>(&client), &client_size);
    if (new_socket == INVALID_SOCKET)
    {
        std::cout << "TCP Socket accept error" << std::endl;
#ifdef WIN32
        std::cout << WSAGetLastError() << std::endl;
#endif
        return 4;
    }
    else
    {
        std::cout << "Connection accepted from IP address " << inet_ntoa(client.sin_addr) << " on port " << ntohs(client.sin_port) << std::endl;
        ssize_t recv_len = recv(new_socket, message_buffer, sizeof(message_buffer), 0);
        std::cout << "Incoming message is:\n" << message_buffer << std::endl;
        std::cout << "Message length was: " << recv_len << std::endl;
        std::string message = "Your message has been received client\n";
        size_t message_length = message.length();
        send(new_socket, message.c_str(), message_length, 0);
    }
#ifdef WIN32
    closesocket(m_socket);
#else
    close(m_socket);
#endif
    return 0;
}

