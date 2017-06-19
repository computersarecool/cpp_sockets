# CPP Sockets
*Testing UDP / TCP Sockets in CPP using OOP*

This was a very small exploration into using sockets in CPP. Specifically I was trying to createa CLI that mimicked the functionality of the UDP and TCP operators in TouchDesigner. 

I also wanted to explore using classes and inheritance as most all of the tutorials I found explain sockets using exclusively C code.

Really this is not that big of a deal and sources I've found suggest using a library like Boost because of the tricky and error-prone nature of programming sockets. 

Still this was a fun exercise and helped me really understand how the differences between TCP and UDP sockets are coded.

## Usage
The CLI allows you to interactively make a:

UDP or TCP, 

server or client,

By asking for:
- Protocol
- client or server

If client:
- Destination IP address
- Destination port

If server:
- Port on which to listen

## Functionality
The UDP client sends a message and exits

The UDP server prints received messages to the console

The TCP client sends a message, waits for a response and exits

The TCP server prints a received message, responds `Your message has been received by client` and exits

## Things to do
#### Things I am going to do:
- [ ] Make cross platform

#### Things I am not going to do:
There is [a lot more that could be done](http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html) but this is outside of my goals with this repo.

- I would have liked to add:
	- Multicast support
	- Threading
	- Use select
	
### License

:copyright: Willy Nolan 2017

[MIT License](http://en.wikipedia.org/wiki/MIT_License)
