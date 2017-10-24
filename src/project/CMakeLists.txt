set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(HEADER_DIR ${CMAKE_SOURCE_DIR}/include/project)
set(HEADER_FILES
  ${HEADER_DIR}/base_socket.h
  ${HEADER_DIR}/tcp_client.h
  ${HEADER_DIR}/tcp_server.h
  ${HEADER_DIR}/udp_client.h
  ${HEADER_DIR}/udp_server.h
  )

add_executable(cpp_sockets main.cpp ${HEADER_FILES})
