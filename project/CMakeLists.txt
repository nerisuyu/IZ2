cmake_minimum_required(VERSION 3.0.0) 
project(email_finder)

file(GLOB SOURCES "*.c" "**/*.c")

add_subdirectory(email_lib)

message("EMAIL_LIB_INCLUDE_DIRS = ${EMAIL_LIB_INCLUDE_DIRS}")
message("EMAIL_LIB_LIBRARIES = ${EMAIL_LIB_LIBRARIES}")

add_subdirectory(utils)

message("UTILS_LIB_INCLUDE_DIRS = ${UTILS_LIB_INCLUDE_DIRS}") 
message("UTILS_LIB_LIBRARIES = ${UTILS_LIB_LIBRARIES}")

add_subdirectory(tests)


message("FINDER_LIB_INCLUDE_DIRS = ${FINDER_LIB_INCLUDE_DIRS}") 
message("FINDER_LIB_LIBRARIES = ${FINDER_LIB_LIBRARIES}")

add_executable(${PROJECT_NAME} main.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage") 
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} " -Wall -Werror -Wpedantic")

target_include_directories(${PROJECT_NAME} PUBLIC ${EMAIL_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${EMAIL_LIB_LIBRARIES} m)

target_include_directories(${PROJECT_NAME} PUBLIC ${UTILS_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${UTILS_LIB_LIBRARIES} m)

