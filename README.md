# Simple CPP Sockets
*A header-only implementation of TCP and UDP sockets in CPP*

## Description
This is a very simple header-only library to use network sockets in C++.

It uses classes, inheritance and other modern C++ features.

Really this library is not that big of a deal and most sources suggest using a library like Boost because of the error-prone nature of programming sockets. 

## Tested on:
- Linux
- Windows

## To Build
- `simple_cpp_sockets.h` is header-only. Just include it in your project.

## To Use
`main.cpp` is a simple functioning example (not all errors are handled gracefully). It creates a CLI that allows you to interactively make a:

UDP or TCP

server or client

By asking for:
- protocol
- client or server

If client:
- destination IP address
- destination port

If server:
- port on which to listen

## Project Structure
- All code is found in `src`

## Functionality
- `simple_cpp_sockets.h` exposes classes for UDP and TCP servers and clients
- Look at `main.cpp` to how these are constructed

## Extra Notes
- There is [a lot more that could be done](http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html) but this is outside the goals of this project
	
### License

:copyright: Willy Nolan 2017

[MIT License](http://en.wikipedia.org/wiki/MIT_License)
