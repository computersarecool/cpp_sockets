#include "simple_cpp_sockets.h"

std::string get_user_input(std::string prompt_message)
{
    std::cout << prompt_message << std::endl;
    std::string user_input;
    getline(std::cin, user_input);

    return user_input;
}

bool validate_input(int input)
{
    if (input != 1 && input != 2)
    {
        std::cout << "Invalid input" << std::endl;
        return false;
    }

    return true;
}

int main() {
    // These could also be enums
    const int invalid_protocol_return = 1;
    const int invalid_sockettype_return = 2;
    const int udp_protocol = 1;
    const int tcp_protocol = 2;
    const int client_socket = 1;
    const int server_socket = 2;

    // Pick protocol
    int socket_protocol = std::stoi(get_user_input("Please pick a protocol. 1 for UDP, 2 for TCP:"));
    if (!validate_input(socket_protocol))
        return invalid_protocol_return;

    // Pick client or server
    int socket_type = std::stoi(get_user_input("Please enter 1 for client or 2 for server:"));
    if (!validate_input(socket_type))
        return invalid_sockettype_return;

    // Pick port (and destination IP address if client)
    u_short socket_port;
    std::string destination_ip;

    // Client
    if (socket_type == client_socket) {
        socket_port = static_cast<u_short>(std::stoi(get_user_input("Please pick a destination port:")));
        destination_ip = get_user_input("Please enter destination ip address (example 127.0.0.1):");
    }

    // Server
    else
    {
        socket_port = static_cast<u_short>(std::stoi(get_user_input("Please enter a port on which to listen")));
    }

    // UDP Protocol
    if (socket_protocol == udp_protocol)
    {
        // Client
        if (socket_type == client_socket)
        {
            UDPClient client(socket_port, destination_ip);
            client.send_message(get_user_input("Please enter your message to send") + "\n");
        }
        // Server
        else if (socket_type == server_socket)
        {
            UDPServer server(socket_port);
            int bind_status = server.socket_bind();

            // Return if there is an issue binding
            if (bind_status)
            {
                return bind_status;
            }
            server.listen();
        }

    }

    // TCP Protocol
    else if (socket_protocol == tcp_protocol)
    {
        // Client
        if (socket_type == client_socket)
        {
            TCPClient client(socket_port, destination_ip);
            int connection_status = client.make_connection();

            // Return if there is an issue binding
            if (connection_status)
            {
                return connection_status;
            }
            client.send_message(get_user_input("Please enter your message to send") + "\n");
        }
        // Server
        else if (socket_type == server_socket)
        {
            TCPServer server(socket_port);
            int bind_status = server.socket_bind();

            // Return if there is an issue binding
            if (bind_status)
            {
                return bind_status;
            }
        }
    }

    return 0;
}
