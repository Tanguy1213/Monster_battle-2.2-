cmake_minimum_required(VERSION 3.9)
project(SFML)

file(GLOB_RECURSE SFML_SRC src/*.cpp include/*.h)

add_executable(SFML ${SFML_SRC})
include_directories(include/)
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/externals)

#SFML
set(SFML_DIR ${EXTERNAL_DIR}/SFML)
set(SFML_BUILD_EXAMPLES FALSE)
add_subdirectory(${SFML_DIR})
include_directories(${SFML_DIR}/include)

LIST(APPEND SFML_LIBRARIES
	sfml-system
	sfml-window
	sfml-graphics
	sfml-audio
	sfml-network)
	
target_link_libraries(SFML ${SFML_LIBRARIES})
