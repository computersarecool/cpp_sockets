set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(IMPLEMENTATION_DIR ${CMAKE_SOURCE_DIR}/src/project)
set(IMPLEMENTATION_FILES
  ${IMPLEMENTATION_DIR}/base_socket.cpp
  ${IMPLEMENTATION_DIR}/tcp_client.cpp
  ${IMPLEMENTATION_DIR}/tcp_server.cpp
  ${IMPLEMENTATION_DIR}/udp_client.cpp
  ${IMPLEMENTATION_DIR}/udp_server.cpp
  )

add_executable(cpp_sockets main.cpp ${IMPLEMENTATION_FILES})
