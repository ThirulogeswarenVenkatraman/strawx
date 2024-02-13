/* texture.h implementation */
#include "SDL2/SDL_image.h"

struct TextureProperties : SDL_Rect {

    TextureProperties() : ptr_to_texture{ nullptr } 
    {
        source_rect = { 0, 0, 0, 0 };
        destin_rect = { 0.0f, 0.0f, 0.0f, 0.0f };
    }

    ~TextureProperties() {
        SDL_DestroyTexture(ptr_to_texture);
        SDL_Log("Destroying Texture [%s]", SDL_GetError());
    }

    SDL_Texture* ptr_to_texture;
    SDL_Rect source_rect;
    SDL_FRect destin_rect;
};

#include "texture.h"

#define INCLUDING_COMMON_SPEC__CH
#include "shared/spec__c.h"

#include <unordered_map>

static std::unordered_map<std::string, TextureProperties> mTextures;

using namespace strawx;
using namespace engine_spec;

void TextureHandler::LoadTexture(std::string_view filename, SDL_Rect source, std::string name)
{
    static SDL_Texture* temp_texture = nullptr;
    
    temp_texture = IMG_LoadTexture(renderer, filename.data());

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

void TextureHandler::DrawTexture(std::string_view name, const float x, const float y)
{
    mTextures[name.data()].destin_rect.x = x;
    mTextures[name.data()].destin_rect.y = y;

    SDL_RenderCopyF(
        renderer,
        mTextures[name.data()].ptr_to_texture,
        &mTextures[name.data()].source_rect,
        &mTextures[name.data()].destin_rect
    );
}

void TextureHandler::SetTextureSize(std::string_view name, const float size)
{
    mTextures.at(name.data()).destin_rect.w *= size;
    mTextures.at(name.data()).destin_rect.h *= size;
}

void engine_spec::clear_textures()
{
    mTextures.clear();
}
