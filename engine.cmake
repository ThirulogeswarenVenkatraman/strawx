
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

set(strawx_src strawx/engine.cc

    strawx/sub_system/input_impl.cc
    strawx/sub_system/texture_impl.cc
)

set(strawx_std cxx_std_17)

set(strawx_deps ${SDL2_LIBRARIES} SDL2_image::SDL2_image)
