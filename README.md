# CPP Sockets
*Simple UDP / TCP Sockets in CPP*

## What this repo does:
This is a very small exploration into using sockets in C++. Specifically this tries to create a CLI to send and receive basic network messages.

This repo also uses classes and inheritance whereas most socket examples use only C code.

Really this is not that big of a deal, most sources suggest using a library like Boost because of the error-prone nature of programming sockets. 

Still it is a fun exercise and helpful to understand the differences in programming TCP and UDP.

## Tested on:
- Linux
- Windows

## To build and use:
This project has been tested on Linux and Windows. It uses CMAKE to build.

- `cd` into the `build` directory and type `cmake -G "${GENERATOR_TYPE}"`.

`${GENERATOR_TYPE}`s that have been tested are `Visual Studio 15 2017 Win64` and `Unix Makefiles`.

## Usage
The CLI allows you to interactively make a:

UDP or TCP, 

server or client,

By asking for:
- protocol
- client or server

If client:
- destination IP address
- destination port

If server:
- port on which to listen

## Functionality
The UDP client sends a message and exits

The UDP server prints received messages to the console

The TCP client sends a message, waits for a response and exits

The TCP server prints a received message, responds `Your message has been received by client` and exits

## Things to do
- There is [a lot more that could be done](http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html) but this is outside the scope of this project
	
### License

:copyright: Willy Nolan 2017

[MIT License](http://en.wikipedia.org/wiki/MIT_License)
