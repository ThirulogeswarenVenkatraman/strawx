#ifndef STRAWX_ENGINE_SPEC_HH
#define STRAWX_ENGINE_SPEC_HH

#include "SDL2/SDL_video.h"
#include "SDL2/SDL_render.h"

// sub-systems
#include "input_handler.h"

struct EngineDef final {

    SDL_Window*     window;
    SDL_Renderer*   renderer;

    uint16_t    state;
    uint16_t    refresh_rate;

    InputHandler    Input;

    void InitSystems();
    void DeInitSystems();

    void FillKeyStates(const Uint8* key_states)
    {
        this->Input.key_states = key_states;
    }
};

namespace Engine
{
    void StartUp(EngineDef& engine, const int width, const int height);
    void ShutDown(EngineDef& engine);
}

#endif

