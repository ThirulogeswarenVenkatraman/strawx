#include "engine.hpp"
#include "engine.spec.h"

#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"

using namespace strawx;

int main(int argc, char** argv)
{
	using Engine::renderer;

	Engine::Initialize(900, 600);

	constexpr float fixed_dt{ 1000.0f / 90.0f };

	float elapsed{ };
	float current{ }, accumulator{ };

	float previous = static_cast<float>(SDL_GetTicks64());

	SDL_Event sdl_event{};

	while (Engine::state) {

		current = static_cast<float>(SDL_GetTicks64());
		elapsed = current - previous;
		previous = current;

		accumulator += elapsed;
				
		while (SDL_PollEvent(&sdl_event))
		{
			switch (sdl_event.type)
			{
			case SDL_QUIT:
				Engine::state = false;
				break;

			case SDL_KEYDOWN:
				fill_keystates(InputHandler::GetInstance(), SDL_GetKeyboardState(nullptr));
				break;

			case SDL_KEYUP:
				fill_keystates(InputHandler::GetInstance(), SDL_GetKeyboardState(nullptr));
				fill_keyrepeat(InputHandler::GetInstance(), sdl_event.key.keysym.scancode);
				break;
			}
		}

		if (InputHandler::GetInstance().IsKeyPressed(SDL_SCANCODE_ESCAPE)) {
			Engine::state = false;
		}

		while (accumulator >= fixed_dt) {
			Game::Update();
			accumulator -= fixed_dt;
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		Game::Render();
		
		SDL_RenderPresent(renderer);
	}

	Engine::ShutDown();

	return EXIT_SUCCESS;
}

void Engine::Initialize(const int width, const int height)
{

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		SDL_Log("Init Error: %s", SDL_GetError());
	}

	window = SDL_CreateWindow (
		"Strawx Engine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		0
	);

	if (!window) {
		SDL_Log("Init Error: %s", SDL_GetError());
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (!renderer) {
		SDL_Log("Init Error %s", SDL_GetError());
	}

	SDL_DisplayMode mode;
	SDL_GetDisplayMode(SDL_GetWindowDisplayIndex(window), 0, &mode);

	refresh_rate = mode.refresh_rate;

	SDL_Log("Refresh Rate: %d", refresh_rate);

	// if everything went OK
	state = true;

	// start Engine subsystem
	TextureManager::Init();
	Game::Start();
}

void Engine::ShutDown() {

	TextureManager::DeInit();

	if (renderer) SDL_DestroyRenderer(renderer);
	SDL_Log("destroying renderer [%s]", SDL_GetError());
	
	if (window) SDL_DestroyWindow(window);
	SDL_Log("destroying window [%s]", SDL_GetError());

	renderer = nullptr;
	window = nullptr;

	SDL_Quit();

	SDL_Log("Destructing Engine");
}

void strawx::fill_keystates(InputHandler& instance, const uint8_t* array)
{
	instance.keystate = array;
}

void strawx::fill_keyrepeat(InputHandler& instance, SDL_Scancode scancode)
{
	instance.repeat[scancode] = 0;
}