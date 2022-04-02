cmake_minimum_required(VERSION 3.14)
project(test_email_finder)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -O0")


file(GLOB SOURCES *.cpp)

find_package(GTest  REQUIRED)

message("EMAIL_LIB_INCLUDE_DIRS = ${EMAIL_LIB_INCLUDE_DIRS}")
message("EMAIL_LIB_LIBRARIES = ${EMAIL_LIB_LIBRARIES}")

message("UTILS_LIB_INCLUDE_DIRS = ${UTILS_LIB_INCLUDE_DIRS}") 
message("UTILS_LIB_LIBRARIES = ${UTILS_LIB_LIBRARIES}")

message("FINDER_LIB_INCLUDE_DIRS = ${FINDER_LIB_INCLUDE_DIRS}") 
message("FINDER_LIB_LIBRARIES = ${FINDER_LIB_LIBRARIES}")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${EMAIL_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${EMAIL_LIB_LIBRARIES} GTest::GTest GTest::Main)

target_include_directories(${PROJECT_NAME} PUBLIC ${UTILS_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${UTILS_LIB_LIBRARIES} GTest::GTest GTest::Main)
