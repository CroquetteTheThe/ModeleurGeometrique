cmake_minimum_required(VERSION 3.8)
project(ModelisateurGeometrique)

set(CMAKE_CXX_STANDARD 14)
file(GLOB sources "*.cpp")
file(GLOB headers "*.h")

set(testing_sources ${sources})
list(REMOVE_ITEM testing_sources ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
list(REMOVE_ITEM sources ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.cpp)
add_executable(ModelisateurGeometrique ${sources} ${headers})
add_executable(testing ${testing_sources} ${headers})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

target_link_libraries(ModelisateurGeometrique ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
target_link_libraries(testing gtest gtest_main)