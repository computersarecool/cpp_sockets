#include "project/tcp_client.h"

TCPClient::TCPClient(int port, const std::string& ip_address) : Socket(SocketType::TYPE_STREAM)
{
	set_address(ip_address);
	set_port(port);
}

// Make a connection
int TCPClient::make_connection()
{
	std::cout << "Connecting" << std::endl;
	if (connect(m_socket, reinterpret_cast<sockaddr*>(&m_addr), sizeof(m_addr)) < 0)
	{
		std::cout << "Connection error" << std::endl;
		return 1;
	}
	std::cout << "connected" << std::endl;
	return 0;
}

// Send an actual message
int TCPClient::send_message(const std::string& message)
{
	int recv_size;
	char server_reply[2000];

	if (send(m_socket, message.c_str(), message.length(), 0) < 0)
	{
		std::cout << "Send failed" << std::endl;
		return 1;
	}
	std::cout << "Data sent" << std::endl;
	if ((recv_size = recv(m_socket, server_reply, 2000, 0)) == SOCKET_ERROR)
	{
		std::cout << "Receive Failed" << std::endl;
	}
	std::cout << server_reply << std::endl;
	return 0;
}

void TCPClient::close()
{
//	closesocket(m_socket);
}
