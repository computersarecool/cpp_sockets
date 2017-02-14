#include "tcp_server.h"

// TCP Server Constructor
TCPServer::TCPServer(const SocketType socket_type, const std::string& ip_address, const int& port) : Socket(socket_type)
{
	set_port(port);
	set_address(ip_address);
	std::cout << "TCP Server created." << std::endl;
};

void TCPServer::socket_bind()
{
	if (bind(m_socket, reinterpret_cast<sockaddr*>(&m_addr), sizeof(m_addr)) == SOCKET_ERROR)
	{
		std::cout << "TCP Socket Bind error." << std::endl;
#ifdef WIN32
		std::cout << WSAGetLastError() << std::endl;
#endif
	}
	std::cout << "TCP Socket Bound." << std::endl;
	listen(m_socket, 3);
	std::cout << "TCP Socket waiting for incoming connections..." << std::endl;

	int client_size = sizeof(sockaddr_in);
	sockaddr_in client;
	SOCKET new_socket;

	while ((new_socket = accept(m_socket, reinterpret_cast<sockaddr*>(&client), &client_size)))
	{
		std::cout << "Connection accepted from" << inet_ntoa(client.sin_addr) << " and " << ntohs(client.sin_port) << std::endl;
		std::string message = "Your message has been received client\n";
		send(new_socket, message.c_str(), message.length(), 0);
	}

	closesocket(m_socket);
}
