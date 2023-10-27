cmake_minimum_required(VERSION 3.26)
project(uttt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_subdirectory(deps/sockpp)

set(COMMON_SOURCE_FILES
  src/common/common.hpp
  src/common/message.hpp
)

set(SERVER_SOURCE_FILES
  ${COMMON_SOURCE_FILES}
  src/server/ServerNetworkManager.hpp
  src/server/ServerNetworkManager.cpp
  src/server/main.cpp
)

set(CLIENT_SOURCE_FILES
  ${COMMON_SOURCE_FILES}
  src/client/main.cpp
)

add_executable(uttt_server ${SERVER_SOURCE_FILES})
add_executable(uttt_client ${CLIENT_SOURCE_FILES})

target_link_libraries(uttt_server Threads::Threads)
target_link_libraries(uttt_client Threads::Threads)

target_link_libraries(uttt_server sockpp)
target_link_libraries(uttt_client sockpp)
