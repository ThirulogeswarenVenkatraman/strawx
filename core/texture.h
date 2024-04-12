#pragma once

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

#include <string_view>

class TextureManager final
{
public:
	int LoadImage(std::string_view filename, SDL_Rect source, float scale = 1.0f);

	void Draw(int u_id, const float x, const float y);

	void setAnimation(std::string_view type);

private:
	friend struct EngineDef;

	inline static uint16_t count{ 0 };
	inline static uint16_t anim_inx{ 0 };
	SDL_Renderer* renderer;

	void StartUp(SDL_Renderer* renderer); 
	void ShutDown();

	TextureManager() = default;
};