# Simple C++ Sockets
*A header-only implementation of TCP and UDP sockets in C++*

## Description
This is a very simple header-only library to use network sockets in C++.

There is also a simple application to demonstrate its functionality.

It uses classes, inheritance and other modern C++ features.

Really this library is not that big of a deal and most sources suggest using a library like Boost because of the error-prone nature of programming sockets. 

## Tested On
- Linux
- Windows

## To Build
- The library `simple_cpp_sockets.h` is header-only (just include it in your project).

- To build and run the test application on Linux open a terminal and run:
    - `cd src`
    - `g++ main.cpp -o main`
    - `./main`

- To build and run the test application on Windows either use Visual Studio directly or open the `Developer Command Prompt` and run:
    - `cd src`
    - `cl main.cpp`
    - `start main.exe`

## Functionality
`main.cpp` is a simple functioning example (not all errors are handled gracefully). 

The compiled test application is a CLI that allows you to interactively create a:

- UDP or TCP
- server or client

By asking for:
- protocol
- client or server

If client:
- destination IP address
- destination port

If server:
- port on which to listen



## To Use
`simple_cpp_sockets.h` contains classes for UDP and TCP servers and clients.

An example looks like:
```
UDPServer server(socket_port);
int bind_status = server.socket_bind();
```
Look at `main.cpp` for the a complete example.

## Project Structure
- `src/simple_cpp_sockets.h` is the library
- `src/main.cpp` is a demo application

## Extra Notes
- There is [a lot more that could be done](https://beej.us/guide/bgnet/) but this is outside the goals of this project
	
### License

:copyright: Willy Nolan 2017

[MIT License](http://en.wikipedia.org/wiki/MIT_License)
