cmake_minimum_required(VERSION 3.26)

project(Engine LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include(strawx/strawx.cmake)

add_executable(Engine ${strawx_src} main.cc)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE
	${SDL2_LIBRARIES} 
	SDL2_image::SDL2_image
)
