#include "engine.hpp"

#include "core/engine_spec.h"

#include "SDL2/SDL_events.h"

int main(int argc, char** argv)
{
    EngineDef strawx; SDL_Event evnt{};

    Engine::StartUp(strawx, 1600, 900);

    using namespace strawx;

    Game::Start();

    while (strawx.state)
    {
        while (SDL_PollEvent(&evnt))
        {
            switch (evnt.type)
            {
            case SDL_QUIT:
                strawx.state = 0;
                break;

            case SDL_KEYDOWN:
                strawx.FillKeyStates(SDL_GetKeyboardState(nullptr));
                break;

            case SDL_KEYUP:
                strawx.FillKeyStates(SDL_GetKeyboardState(nullptr));
                break;
            }
        }

        Game::Update();

        SDL_RenderClear(strawx.renderer);

        Game::Render();

        SDL_RenderPresent(strawx.renderer);

    }

    Engine::ShutDown(strawx);

    return EXIT_SUCCESS;
}

