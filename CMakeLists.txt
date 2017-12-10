cmake_minimum_required(VERSION 3.8)
project(ModelisateurGeometrique)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Shapes/Drawable.h UI/Window.cpp UI/Window.h Utils/Color.cpp Utils/Color.h Utils/Vector3f.cpp Utils/Vector3f.h Shapes/Shape.cpp Shapes/Shape.h Readers/ShapeReader.h Readers/OFFReader.cpp Readers/OFFReader.h UI/Widget.h UI/Label.cpp UI/Label.h UI/TextInput.cpp UI/TextInput.h Events/EventType.h Events/Event.h Events/MouseClickEvent.cpp Events/MouseClickEvent.h Events/MouseButton.h Events/KeyboardEvent.cpp Events/KeyboardEvent.h Events/EventListener.h UI/Button.cpp UI/Button.h Utils/glUtils.cpp Utils/glUtils.h Events/MouseMotionEvent.cpp Events/MouseMotionEvent.h UI/Pane.cpp UI/Pane.h UI/Slider.cpp UI/Slider.h Shapes/Camera.cpp Shapes/Camera.h Shapes/Light.h Shapes/Light.cpp UI/ItemPane.h UI/ItemPane.cpp UI/Item.h UI/Item.cpp Events/DrawableCreationEvent.h Events/DrawableCreationEvent.cpp UI/AbstractPane.h UI/AbstractPane.cpp Events/DrawableDestroyEvent.h Events/DrawableDestroyEvent.cpp Shapes/DrawableType.h TestLight.h TestLight.cpp TestCamera.cpp TestCamera.h)
add_executable(ModelisateurGeometrique ${SOURCE_FILES} TestCamera.cpp TestCamera.h)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(ModelisateurGeometrique ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})