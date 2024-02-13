#ifndef STRAWX_COMMON_HEADER__HH
#define STRAWX_COMMON_HEADER__HH

#include "SDL2/SDL_render.h"

constexpr uint16_t NUM_KEYS = { 512 };

inline struct
{
	uint8_t repeat	[NUM_KEYS];
	uint8_t state	[NUM_KEYS];
	uint8_t down	[NUM_KEYS];
	uint8_t up		[NUM_KEYS];

	void clear_states()
	{
		memset(down, 0, NUM_KEYS);
		memset(up, 0, NUM_KEYS);
	}

} KeyboardStates;


namespace engine_specific
{
	void clear_textures(void);

	inline SDL_Renderer* renderer = nullptr;
}

#endif
