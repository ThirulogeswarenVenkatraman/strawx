#pragma once

#include <stdint.h>

constexpr uint16_t ARR_SZ = { 512 };

inline struct 
{
	uint8_t repeat	[ARR_SZ];
	uint8_t state	[ARR_SZ];
	uint8_t down	[ARR_SZ];
	uint8_t up		[ARR_SZ];

	void clear_states()
	{
		memset(down, 0, ARR_SZ);
		memset(up, 0, ARR_SZ);
	}

} KeyboardStates;

#include <SDL2/SDL_render.h>

inline SDL_Renderer* mRenderer = nullptr;
