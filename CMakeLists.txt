cmake_minimum_required(VERSION 3.6)
project(untitled)

add_executable(GET main.c get_next_line.c libft/libft.h libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strnew.c)

target_link_libraries(GET ${CMAKE_SOURCE_DIR}/libft.a)