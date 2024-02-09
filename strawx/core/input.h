#ifndef STRAWX_ENGINE_INPUT_H
#define STRAWX_ENGINE_INPUT_H

#include "SDL2/SDL_scancode.h"

namespace strawx::InputHandler {

	[[nodiscard]] bool IsKeyDown(SDL_Scancode scancode);

	[[nodiscard]] bool IsKeyReleased(SDL_Scancode scancode);

	[[nodiscard]] bool IsKeyPressed(SDL_Scancode scancode);
}

#endif
