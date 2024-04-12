#include "engine_spec.h"

#include "SDL2/SDL.h"

void EngineDef::StartUp(const int width, const int height)
{

    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
    {
        SDL_Log("%s", SDL_GetError());
        return;
    }

    this->window = SDL_CreateWindow(
        "strawx",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, height, SDL_WINDOW_RESIZABLE
    );

    if (!this->window) {
        SDL_Log("%s", SDL_GetError());
        return;
    }

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (!this->renderer)
    {
        SDL_Log("%s", SDL_GetError());
        return;
    }

    // if everything went ok
    this->state = 1u;

    SDL_DisplayMode display_mode;
    SDL_GetDisplayMode(SDL_GetWindowDisplayIndex(this->window), 0, &display_mode);

    this->refresh_rate = display_mode.refresh_rate;

    SDL_Log("refresh rate: %u", this->refresh_rate);

    // sub-systems
    InputSystem.StartUp();
    TextureSystem.StartUp(this->renderer);

    static Handler engine_handler{ this };
    Handler::e_handler = &engine_handler;
}

void EngineDef::ShutDown()
{
    TextureSystem.ShutDown();
    InputSystem.ShutDown();

    if (this->renderer)
    {
        SDL_DestroyRenderer(this->renderer);
    }

    if (this->window)
    {
        SDL_DestroyWindow(this->window);
    }

    this->renderer = nullptr;
    this->window = nullptr;

    SDL_Log("System ShutDown");
}
