#include "engine_spec.h"

#include "SDL2/SDL.h"

void Engine::StartUp(EngineDef& engine, const int width, const int height)
{

    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
    {
        SDL_Log("%s", SDL_GetError());
        return;
    }

    engine.window = SDL_CreateWindow(
        "strawx",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, height, 0
    );

    if (!engine.window) {
        SDL_Log("%s", SDL_GetError());
        return;
    }

    engine.renderer = SDL_CreateRenderer(engine.window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (!engine.renderer)
    {
        SDL_Log("%s", SDL_GetError());
        return;
    }

    // if everything went ok
    engine.state = 1u;

    SDL_DisplayMode display_mode;
    SDL_GetDisplayMode(SDL_GetWindowDisplayIndex(engine.window), 0, &display_mode);

    engine.refresh_rate = display_mode.refresh_rate;

    SDL_Log("refresh rate: %u", engine.refresh_rate);

    engine.InitSystems();
}

void Engine::ShutDown(EngineDef& engine)
{
    engine.DeInitSystems();

    if (engine.renderer)
    {
        SDL_DestroyRenderer(engine.renderer);
    }

    if (engine.window)
    {
        SDL_DestroyWindow(engine.window);
    }

    engine.renderer = nullptr;
    engine.window = nullptr;

    SDL_Log("System ShutDown");
}

void EngineDef::InitSystems()
{
    this->Input.StartUp();
    
}

void EngineDef::DeInitSystems()
{
    this->Input.ShutDown();
}