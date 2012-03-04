cmake_minimum_required (VERSION 2.6)
project (game)

set (SRC_FILES "main.cpp" "floor.cpp" "map.cpp" "item.cpp" "object.cpp")

add_executable ("game" ${SRC_FILES})
