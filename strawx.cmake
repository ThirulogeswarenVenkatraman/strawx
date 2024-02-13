
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

set(strawx_src strawx/engine.cc
    strawx/core/input.cc
    strawx/core/texture.cc
)

set(strawx_deps ${SDL2_LIBRARIES} SDL2_image::SDL2_image)
