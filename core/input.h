#pragma once

#include "SDL2/SDL_scancode.h"
#include <array>

namespace strawx {

	class InputHandler final
	{
	public:
		_STRAWX_NODISCARD bool IsKeyDown(SDL_Scancode scancode)
		{
			return { keystate && keystate[scancode] };
		}

		_STRAWX_NODISCARD bool IsKeyPressed(SDL_Scancode scancode)
		{
			if (keystate && (!repeat[scancode]) && keystate[scancode]) {
				repeat[scancode] = 1;
				return true;
			}
			return false;
		}

		_STRAWX_NODISCARD static InputHandler& GetInstance()
		{
			static InputHandler handler{};
			return handler;
		}

	private:
		const uint8_t* keystate;
		std::array<uint8_t, SDL_NUM_SCANCODES> repeat;

	private:
		InputHandler();
		~InputHandler();

		friend void fill_keystates(InputHandler& instance, const uint8_t* array);
		friend void fill_keyrepeat(InputHandler& instance, SDL_Scancode scancode);

	};

}
