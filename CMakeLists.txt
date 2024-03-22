
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_library(engine_strawx OBJECT "engine.hpp"
	"core/engine.cpp"
	"core/engine.spec.h"

	"core/input.cpp"
	
	"core/input.h"

	"core/texture.cpp"
	"core/texture.h"
)

target_compile_features(engine_strawx PUBLIC cxx_std_17)
target_compile_definitions(engine_strawx PUBLIC _STRAWX_NODISCARD=[[nodiscard]])

target_include_directories(engine_strawx PUBLIC ${CMAKE_SOURCE_DIR}/strawx)

target_link_libraries(engine_strawx PUBLIC ${SDL2_LIBRARIES} SDL2_image::SDL2_image)
