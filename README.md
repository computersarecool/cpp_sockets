#CPP Sockets

This was a very small exploration into sockets. Specifically I was trying to recreate the functionality of the UDP and TCP operators in TouchDesigner in a CLI. I also wanted to explore using classes and inheritance as most all of the tutorials I found explain sockets using exclusively C code. It was the first project a set out to do on my own using C++. 

Really this is not that big of a deal, most things I have read suggest using a library like Boost because of the tricky and error-prone nature of sockets. Still this was a fun exercise and helped me really understand how the differences between TCP and UDP sockets are coded.

## Usage
The CLI Allows you to interactively make a:

UDP or TCP, server or client

By asking for:
- Protocol
- Client or Server

If client:
- Destination IP address (if client)
- Destination port (if client)

If server:
- Port on which to listen

## Functionality
The UDP Client sends a message and exist

The UDP Server prints received messages to the console

The TCP client sends a message, waits for a response and exits

The TCP server prints a received message, responds "Your mressage has been received by client" and exits

## Things to do
#### Things I am going to do:
- [ ] Make cross platform

#### Things I am not going to do:
There is [a lot more to do](http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html) but for the most part I have accomplished what I want to do.
Things I could have done but am forgoing:
- I would have liked to add:
	- Multicast support
	- Threading
	- Use select
	
### License
[MIT](http://en.wikipedia.org/wiki/MIT_License)
