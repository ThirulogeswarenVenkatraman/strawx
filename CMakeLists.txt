# strawx CMakeLists.txt
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_library(strawx_engine OBJECT main.cpp
    core/engine.cpp
    core/input_handler.cpp
)

target_compile_features(strawx_engine PUBLIC cxx_std_17)

target_include_directories(strawx_engine PRIVATE ${CMAKE_SOURCE_DIR}/strawx)

target_link_libraries(strawx_engine PUBLIC SDL2::SDL2 SDL2_image SDL2_ttf)
