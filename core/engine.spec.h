#pragma once

#include "SDL2/SDL_video.h"
#include "SDL2/SDL_render.h"

namespace Engine
{
	void Initialize(const int width, const int height);
	void ShutDown();

	inline SDL_Window* window{ nullptr };
	inline SDL_Renderer* renderer{ nullptr };

	inline uint16_t state{0};
	inline uint16_t refresh_rate{0};

	namespace TextureManager
	{
		void Init();
		void DeInit();
	}

}



