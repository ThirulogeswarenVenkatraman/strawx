# strawx CMakeLists.txt
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

add_library(strawx_engine OBJECT main.cpp
    core/engine.cpp

    core/handler.h
    core/handler.cpp

    core/input_handler.h
    core/input_handler.cpp

    core/texture.h 
    core/texture.cpp
    
    util/vector_2d.h
)

target_compile_features(strawx_engine PUBLIC cxx_std_17)

target_include_directories(strawx_engine PRIVATE ${CMAKE_SOURCE_DIR}/strawx)

target_link_libraries(strawx_engine PUBLIC SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)
