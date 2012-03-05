# Project Settings
cmake_minimum_required (VERSION 2.6)
project (ss14)

set (CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Modules)

set (EXECUTABLE "ss14")
set (SRC_FILES
src/main.cpp
src/map.cpp
src/maploader.cpp
src/tile.cpp)

# Libraries
set (CMAKE_FIND_FRAMEWORK "NEVER")
find_package (SFML REQUIRED system window graphics)
set (CMAKE_FIND_FRAMEWORK "ONCE")
find_package (OpenGL REQUIRED)

# Copy art assets
file (COPY tiles DESTINATION ${CMAKE_BINARY_DIR})
file (COPY map.png DESTINATION ${CMAKE_BINARY_DIR})

# Build Settings
set (PROJECT_INCLUDES ${SFML_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})
include_directories (src)

# Build setup
add_executable (${EXECUTABLE} ${SRC_FILES})

include_directories (${PROJECT_INCLUDES})
target_link_libraries (${EXECUTABLE} ${SFML_LIBRARIES})

if (APPLE)
  message ( "Apple environment detected. Binding to OpenGL framework." )
  target_link_libraries (${EXECUTABLE} "-framework OpenGL")
else ()
  message ( "Assuming POSIX environment and binding with OpenGL." )
  target_link_libraries (${EXECUTABLE} ${OPENGL_LIBRARIES})
endif ()
