#ifndef STRAWX_ENGINE_INPUT_HANDLER__HH
#define STRAWX_ENGINE_INPUT_HANDLER__HH

#include "SDL2/SDL_scancode.h"

namespace strawx::InputHandler {

	[[nodiscard]] bool IsKeyDown(SDL_Scancode scancode);

	[[nodiscard]] bool IsKeyReleased(SDL_Scancode scancode);

	[[nodiscard]] bool IsKeyPressed(SDL_Scancode scancode);

}

#endif
