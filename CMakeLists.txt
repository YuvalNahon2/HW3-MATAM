cmake_minimum_required(VERSION 3.6)
project(HW3)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES EscapeTechnion.c EscapeTechnion.h
        Costumer.c Costumer.h EscapeRoom.c EscapeRoom.h Company.c Company.h Order.c Order.h Email.h main.c)

add_executable(HW3 ${SOURCE_FILES})
target_link_libraries(HW3 ${CMAKE_SOURCE_DIR}/libmtm.a)