#pragma once

#include "SDL2/SDL_rect.h"

#include <string_view>
#include <unordered_map>

namespace strawx::TextureHandler {

    void LoadTexture(std::string_view filename, const SDL_Rect source, const std::string name);

    void DrawTexture(std::string_view name, const float x, const float y);

    void SetTextureSize(std::string_view name, const float size);

}