#include "project/tcp_server.h"

TCPServer::TCPServer(u_short port, const std::string& ip_address) : Socket(SocketType::TYPE_STREAM)
{
	set_port(port);
	set_address(ip_address);
	std::cout << "TCP Server created." << std::endl;
};

// Socket Bind
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

	socklen_t client_size = sizeof(sockaddr_in);
	sockaddr_in client;
	SOCKET new_socket;
	char message_buffer[512];

	// TODO: Thread this
	new_socket = accept(m_socket, reinterpret_cast<sockaddr*>(&client), &client_size);
	if (new_socket == INVALID_SOCKET)
	{
		std::cout << "TCP Socket accept error" << std::endl;
#ifdef WIN32
		std::cout << WSAGetLastError() << std::endl;
#endif
	} 
	else
	{
		std::cout << "Connection accepted from IP address " << inet_ntoa(client.sin_addr) << " on port " << ntohs(client.sin_port) << std::endl;
		int recv_len = recv(new_socket, message_buffer, sizeof(message_buffer), 0);
		std::cout << "Incoming message is:\n" << message_buffer << std::endl;
                std::cout << "Message length was: " << recv_len << std::endl;
		std::string message = "Your message has been received client\n";
		int message_length = static_cast<int>(message.length());
		send(new_socket, message.c_str(), message_length, 0);
	}
#ifdef WIN32
	closesocket(m_socket);
#else
	close(m_socket);
#endif
}
