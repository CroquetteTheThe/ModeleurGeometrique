cmake_minimum_required(VERSION 3.8)
project(ModelisateurGeometrique)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Drawable.h Window.cpp Window.h Color.cpp Color.h Vector3d.cpp Vector3d.h Shape.cpp Shape.h)
add_executable(ModelisateurGeometrique ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(ModelisateurGeometrique ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})