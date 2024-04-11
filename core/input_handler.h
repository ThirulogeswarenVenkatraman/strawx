#ifndef STRAWX_INPUT_HANDLER_HH
#define STRAWX_INPUT_HANDLER_HH

#include "SDL2/SDL_scancode.h"
#include "SDL2/SDL_log.h"

class InputHandler final
{
public:
    bool isKeyDown(SDL_Scancode key)
    {
        return key_states && key_states[key];
    }
    
private:
    const Uint8* key_states;

    void StartUp();
    void ShutDown();

    InputHandler() = default;
    ~InputHandler() = default;
    
    friend struct EngineDef;
};

#endif
