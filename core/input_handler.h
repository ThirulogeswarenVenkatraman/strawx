#ifndef STRAWX_INPUT_HANDLER_HH
#define STRAWX_INPUT_HANDLER_HH

#include "SDL2/SDL_scancode.h"
#include "SDL2/SDL_log.h"

#include <array>

class InputHandler final
{
public:
    bool isKeyDown(SDL_Scancode key)
    {
        return key_states && key_states[key];
    }

    bool isKeyPressed(SDL_Scancode key)
    {
        if (isKeyDown(key) && (!repeat[key])) {
            repeat[key] = 1;
            return true;
        }
        return false;
    }
    
private:
    const Uint8* key_states{ nullptr };
    std::array<Uint8, SDL_NUM_SCANCODES> repeat{ 0 };

    void StartUp();
    void ShutDown();

    InputHandler() = default;
    ~InputHandler() = default;
    
    friend struct EngineDef;
};

#endif
