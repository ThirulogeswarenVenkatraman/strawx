#include "input_handler.h"

void InputHandler::StartUp()
{
    key_states = nullptr;
    repeat.fill(0);
    SDL_Log("InputHandler Constructed");
}

void InputHandler::ShutDown()
{
    key_states = nullptr;
    SDL_Log("InputHandler Destroyed");
}