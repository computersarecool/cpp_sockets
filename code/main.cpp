#include "udp_server.h"
#include "udp_client.h"
#include "tcp_client.h"
#include <clocale>
#include <iostream>

int main()
{
  //UDPServer udp_server;
  //udp_server.socket_bind();
  //udp_server.listen();
  
  //UDPClient udp;
  //std::string message;
  //std::cout << "Please enter your message" << std::endl;
  //getline(std::cin, message);
  //udp.send_message(message + "\n");

	TCPClient tcp_client(Socket::SocketType::TYPE_STREAM, "216.58.194.206", 80);
	int result = tcp_client.make_connection();
	tcp_client.name_to_host("www.google.com");
	std::string message = "GET / HTTP/1.1\r\n\r\n";
	tcp_client.send_message(message);
	return 0;
}
