#include "texture.h"

#include "SDL2/SDL_image.h"

using namespace strawx;

struct TextureProperties {

    TextureProperties() : ptr_to_texture{ nullptr } 
    {
        source_rect = { 0, 0, 0, 0 };
        destin_rect = { 0.0f, 0.0f, 0.0f, 0.0f };
    }

    ~TextureProperties() {
        SDL_DestroyTexture(ptr_to_texture);
        SDL_Log("Destroyed Texture [%s]", SDL_GetError());
    }

    SDL_Texture* ptr_to_texture;
    SDL_Rect source_rect;
    SDL_FRect destin_rect;
};

#include "common.h"
#include <unordered_map>

static std::unordered_map<std::string, TextureProperties> mTextures;

void TextureHandler::LoadTexture(std::string filename, SDL_Rect source, std::string name)
{
    static SDL_Texture* temp_texture = nullptr;
    
    temp_texture = IMG_LoadTexture(mRenderer, filename.c_str());

    if (!temp_texture) {
        SDL_Log("%s", IMG_GetError());
        return;
    }

    mTextures[name].ptr_to_texture = temp_texture;
    temp_texture = nullptr;

    mTextures[name].source_rect = source;
    mTextures[name].destin_rect.w = static_cast<float>(source.w);
    mTextures[name].destin_rect.h = static_cast<float>(source.h);

    SDL_Log("Loaded %s", name.c_str());
}

void TextureHandler::DrawTexture(const std::string name, const float x, const float y)
{
    mTextures[name].destin_rect.x = x;
    mTextures[name].destin_rect.y = y;

    SDL_RenderCopyF(
        mRenderer,
        mTextures[name].ptr_to_texture,
        &mTextures[name].source_rect,
        &mTextures[name].destin_rect
    );
}

void TextureHandler::SetTextureSize(const std::string name, const float size)
{
    mTextures.at(name).destin_rect.w *= size;
    mTextures.at(name).destin_rect.h *= size;
}

void TextureHandler::ClearTextures()
{
    mTextures.clear();
}
