#include "texture.h"

#include "SDL2/SDL_image.h"

#include <vector>

struct ImageProperties
{
	SDL_Rect src_rect;
	SDL_FRect dst_rect;

	std::vector<SDL_Texture*> sprite_sheets;

	ImageProperties(SDL_Rect source_dst) :
		src_rect{ source_dst },
		dst_rect{ 0.0f, 0.0f, 0.0f, 0.0f }
	{
		sprite_sheets.reserve(9);
	}
};

static std::vector<ImageProperties> c_textures;

int TextureManager::LoadImage(std::string_view filename, SDL_Rect source, float scale)
{
	c_textures.emplace_back(ImageProperties{ source });

	c_textures[count].sprite_sheets = IMG_LoadTexture(this->renderer, filename.data());

	if (!c_textures[count].texture)
	{
		SDL_Log("%s", IMG_GetError());
		return -1;
	}

	c_textures[count].dst_rect.w = static_cast<float>(source.w) * scale;
	c_textures[count].dst_rect.h = static_cast<float>(source.h) * scale;

	return count++;
}

void TextureManager::Draw(const int u_id, const float x, const float y)
{
	c_textures[u_id].dst_rect.x = x;
	c_textures[u_id].dst_rect.y = y;

	SDL_RenderCopyF(
		this->renderer,
		c_textures[u_id].texture,
		&c_textures[u_id].src_rect,
		&c_textures[u_id].dst_rect
	);
}

void TextureManager::setAnimation(std::string_view type)
{
}

void TextureManager::StartUp(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	c_textures.reserve(30);
}

void TextureManager::ShutDown()
{
	renderer = nullptr;
	c_textures.clear();
}
