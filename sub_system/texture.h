#ifndef STRAWX_TEXTURE_HANDLER__HH
#define STRAWX_TEXTURE_HANDLER__HH

#include "SDL2/SDL_rect.h"
#include <string_view>

namespace strawx::TextureHandler {

    void LoadTexture(const std::string filename, const SDL_Rect source, const std::string name);

    void DrawTexture(std::string_view name, const float x, const float y);

    void SetTextureSize(std::string_view name, const float size);
}

#endif
