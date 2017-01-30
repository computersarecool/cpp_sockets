#include "udp_server.h"
#include "udp_client.h"

int main()
{
  UDPServer udp;
  udp.listen();
  //UDPClient udp;
  //udp.send_message("Test");
  return 0;
}
