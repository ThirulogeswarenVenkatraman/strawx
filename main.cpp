#include "engine.hpp"

#include "core/engine_spec.h"
#include "core/handler.h"

#include "SDL2/SDL_events.h"
#include "SDL2/SDL_timer.h"

int main(int argc, char** argv)
{
    EngineDef strawx; SDL_Event evnt{};
    
    strawx.StartUp(1100, 600);

    using namespace strawx;

    Game::Start();

    constexpr float fixed_dt{ 1000.0f / 90.0f };

    float elapsed{ };
    float current{ }, accumulator{ };

    float previous = static_cast<float>(SDL_GetTicks64());

    while (strawx.state)
    {
        current = static_cast<float>(SDL_GetTicks64());
        elapsed = current - previous;
        previous = current;

        accumulator += elapsed;

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
                strawx.ResetKeyStates(evnt.key.keysym.scancode);
                break;
            }
        }

        if (Handlers->Input.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
            strawx.state = false;
        }

        while (accumulator >= fixed_dt) {
            Game::Update();
            accumulator -= fixed_dt;
        }

        SDL_SetRenderDrawColor(strawx.renderer, 0, 0, 0, 255);
        SDL_RenderClear(strawx.renderer);

        Game::Render();

        SDL_RenderPresent(strawx.renderer);

    }

    strawx.ShutDown();

    return EXIT_SUCCESS;
}

