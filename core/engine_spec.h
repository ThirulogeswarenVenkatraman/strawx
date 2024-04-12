#ifndef STRAWX_ENGINE_SPEC_HH
#define STRAWX_ENGINE_SPEC_HH

#include "SDL2/SDL_video.h"
#include "SDL2/SDL_render.h"

#include "handler.h"

struct EngineDef final {

    SDL_Window*     window;
    SDL_Renderer*   renderer;

    uint16_t    state;
    uint16_t    refresh_rate;

    InputHandler    InputSystem;
    TextureManager  TextureSystem;

    void StartUp(const int width, const int height);
    void ShutDown();
    
    void FillKeyStates(const Uint8* key_states)
    {
        this->InputSystem.key_states = key_states;
    }

    void ResetKeyStates(SDL_Scancode key)
    {
        this->InputSystem.repeat[key] = 0;
    }

};

#endif

