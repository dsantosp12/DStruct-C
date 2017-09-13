cmake_minimum_required(VERSION 3.6)
project(C_DStruct)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
link_libraries(check)

set(SOURCE_FILES
        test/main_test.c
        src/LinkedList/linked_list.h
        src/LinkedList/linked_list.c
        src/Queue/queue.h
        src/Queue/queue.c src/Stack/stack.c src/Stack/stack.h)

add_executable(C_DStruct ${SOURCE_FILES})