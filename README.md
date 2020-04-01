# Simple CPP Sockets
*A header-only implementation of TCP and UDP sockets in CPP*

## Description
This is a very simple header-only library to use network sockets in C++.

There is also a simple application to demonstrate its functionality.

It uses classes, inheritance and other modern C++ features.

Really this library is not that big of a deal and most sources suggest using a library like Boost because of the error-prone nature of programming sockets. 

## Tested On
- Linux
- Windows

## To Build
- `simple_cpp_sockets.h` is header-only (just include it in your project).
- To build and run the test application on Linux:
    - `cd src`
    - `g++ main.cpp -o main`
    - `./main`

- To build and run the test application on Windows, use Visual Studio or install it, open the "Developer Command Prompt" and run:
    - `cd src`
    - `cl main.cpp`
    - Double click on `main.exe`

## To Use
`main.cpp` is a simple functioning example (not all errors are handled gracefully). 

Run the compiled demo application from the command line.
It is a CLI that allows you to interactively make a:

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
- `src/simple_cpp_sockets.h` is the library
- `src/main.cpp` is a simple demo application

## Functionality
- `simple_cpp_sockets.h` contains classes for UDP and TCP servers and clients
- Look at `main.cpp` to how these are constructed

## Extra Notes
- There is [a lot more that could be done](http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html) but this is outside the goals of this project
	
### License

:copyright: Willy Nolan 2017

[MIT License](http://en.wikipedia.org/wiki/MIT_License)
