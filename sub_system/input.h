#ifndef STRAWX_INPUT_HANDLER__H
#define STRAWX_INPUT_HANDLER__H

#include "SDL2/SDL_scancode.h"

namespace strawx::InputHandler {

	[[nodiscard]] bool IsKeyDown(SDL_Scancode scancode);

	[[nodiscard]] bool IsKeyReleased(SDL_Scancode scancode);

	[[nodiscard]] bool IsKeyPressed(SDL_Scancode scancode);
}

#endif
