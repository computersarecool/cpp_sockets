#include "udp_server.h"
#include "udp_client.h"
#include "tcp_client.h"
#include "tcp_server.h"

std::string get_message()
{
	std::string message;
	std::cout << "Please enter your message to send" << std::endl;
	getline(std::cin, message);
	return message + "\n";
}

int main()
{
	// TODO: Make name_to_host
	//tcp_client.name_to_host("www.google.com");

	// Pick the protocol
	std::string protocol;
	std::cout << "Please pick a protocol. 1 for UDP, 2 for TCP:" << std::endl;
	getline(std::cin, protocol);
	int socket_protocol = atoi(protocol.c_str());

	// Pick client or server
	std::string type;
	std::cout << "Please enter 1 for client or 2 for server:" << std::endl;
	getline(std::cin, type);
	int socket_type = atoi(type.c_str());

	std::string destination_ip;
	if (socket_type == 1)
	{
		std::cout << "Please enter destination ip address (example 127.0.0.1):" << std::endl;
		getline(std::cin, destination_ip);
	}

	// Pick the port
	std::string port;
	std::cout << "Please pick a " << ((socket_type == 1) ? "destination port:" : "port on which to listen:") << std::endl;
	getline(std::cin, port);
	int socket_port = atoi(port.c_str());

	// UDP Protocol
	if (socket_protocol == 1) 
	{
		// Client
		if (socket_type == 1) 
		{
			UDPClient client(socket_port, destination_ip);
			client.send_message(get_message());
		}
		// Server
		else if (socket_type == 2) 
		{
			// By default it listens on "0.0.0.0"
			UDPServer server(socket_port);
			server.socket_bind();
			server.listen();
		}
		// Invalid
		else 
		{
			std::cout << "Your socket client / server choice was invalid" << std::endl;
			return 1;
		}
	}

	// TCP Protocol
	else if (socket_protocol == 2) 
	{
		// Client
		if (socket_type == 1) 
		{
			TCPClient client(socket_port, destination_ip);
			client.make_connection();
			client.send_message(get_message());
		}
		// Server
		else if (socket_type == 2)
		{
			TCPServer server(socket_port);
			server.socket_bind();
		}
		// Invalid
		else
		{
			std::cout << "Your socket client / server choice was invalid" << std::endl;
			return 1;
		}
	}

	// Invalid
	else
	{
		std::cout << "Your protocol choice was invalid" << std::endl;
		return 1;
	}

	return 0;
}
