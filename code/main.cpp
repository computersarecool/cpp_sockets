#include "udp_server.h"
#include "udp_client.h"

int main()
{
  UDPServer udp_server;
udp_server.socket_bind();
  udp_server.listen();
  //UDPClient udp;
  //udp.send_message("Test");
  return 0;
}
