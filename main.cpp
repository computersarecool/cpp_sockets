#include "simple_cpp_sockets.h"

std::string get_user_input(std::string prompt_message)
{
    std::cout << prompt_message << std::endl;
    std::string user_input;
    getline(std::cin, user_input);
    return user_input;
}

int validate_input(int input, int error_code)
{
    if (input != 1 && input != 2)
    {
        std::cout << "Invalid input"<<std::endl;
        return error_code;
    }

    return 0;
}

int main()
{
    // Pick the protocol
    int socket_protocol = std::stoi(get_user_input("Please pick a protocol. 1 for UDP, 2 for TCP:"));
    validate_input(socket_protocol, 1);

    // Pick the socket type
    int socket_type = std::stoi(get_user_input("Please enter 1 for client or 2 for server:"));
    validate_input(socket_protocol, 2);

    // Pick port (and destination ip if client)
    u_short socket_port;
    std::string destination_ip;

    // Client
    if (socket_type == 1) {
        socket_port = static_cast<u_short>(std::stoi(get_user_input("Please pick a destination port:")));
        destination_ip = get_user_input("Please enter destination ip address (example 127.0.0.1):");
    }

    // Server
    else
    {
        socket_port = static_cast<u_short>(std::stoi(get_user_input("Please enter a port on which to listen")));
    }

    // UDP Protocol
    if (socket_protocol == 1)
    {
        // Client
        if (socket_type == 1)
        {
            UDPClient client(socket_port, destination_ip);
            client.send_message(get_user_input("Please enter your message to send") + "\n");
        }
            // Server
        else if (socket_type == 2)
        {
            UDPServer server(socket_port);
            int bind_status = server.socket_bind();
            if (bind_status)
            {
                return bind_status;
            }
            server.listen();
        }

    }

    // TCP Protocol
    else if (socket_protocol == 2)
    {
        // Client
        if (socket_type == 1)
        {
            TCPClient client(socket_port, destination_ip);
            int connection_status = client.make_connection();
            if (connection_status)
            {
                return connection_status;
            }
            client.send_message(get_user_input("Please enter your message to send") + "\n");
        }
        // Server
        else if (socket_type == 2)
        {
            TCPServer server(socket_port);
            int bind_status = server.socket_bind();
            if (bind_status)
            {
                return bind_status;
            }
        }
    }

    return 0;
}
