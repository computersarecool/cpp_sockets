#include "tcp_client.h"

TCPClient::TCPClient(SocketType socket_type, const std::string& ip_address, int port) : Socket(socket_type)
{
	set_address(ip_address);
	set_port(port);
}

int TCPClient::make_connection()
{
	std::cout << "Connecting" << std::endl;
	if (connect(m_socket, (struct sockaddr*) &m_addr, sizeof(m_addr)) < 0)
	{
		std::cout << "Connection error" << std::endl;
		return 1;
	}
	std::cout << "connected" << std::endl;
	return 0;
}

int TCPClient::send_message(std::string message)
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
	closesocket(m_socket);
}