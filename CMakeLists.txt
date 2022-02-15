cmake_minimum_required(VERSION 3.19)
project(new)

set(CMAKE_CXX_STANDARD 20)

add_executable(new en_decrypter.c opensslconf.h o_aes.h)

link_libraries(crypto)
