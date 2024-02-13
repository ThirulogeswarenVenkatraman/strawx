#include "engine.h"

#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"


struct Engine {
	Engine(const int width, const int height);
	~Engine();

	SDL_Window* window;
	SDL_Renderer* renderer;

	uint8_t engine_state;
	uint16_t refresh_rate;
};

#define INCLUDING_COMMON_SPEC__CH
#include "sub_system/shared/spec__c.h"

int main(int argc, char** argv)
{
	using namespace strawx;
 
	Engine core{ 1000, 600 };

	engine_spec::renderer = core.renderer;

	Game::Start();

	constexpr float fixed_dt{ 1000.0f / 90.0f };

	float elapsed{ };
	float current{ }, accumulator{ };

	float previous = static_cast<float>(SDL_GetTicks64());

	while (core.engine_state) {
		
		KeyboardStates.clear_states();

		current = static_cast<float>(SDL_GetTicks64());
		elapsed = current - previous;
		previous = current;

		accumulator += elapsed;

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (auto& [repeat, state, down, up] = KeyboardStates; event.type)
			{
			case SDL_QUIT:
				core.engine_state = false;
				break;
			
			case SDL_KEYDOWN:
				state[event.key.keysym.scancode] = 1;
				down[event.key.keysym.scancode] = 1;
				break;

			case SDL_KEYUP:
				state[event.key.keysym.scancode] = 0;

				repeat[event.key.keysym.scancode] = 0;
				up[event.key.keysym.scancode] = 1;
				break;
			}
		}

		if (InputHandler::IsKeyPressed(SDL_SCANCODE_ESCAPE))
			core.engine_state = false;

		while (accumulator >= fixed_dt) {
			Game::Update();
			accumulator -= fixed_dt;
		}

		SDL_SetRenderDrawColor(core.renderer, 0, 0, 0, 255);
		SDL_RenderClear(core.renderer);

		Game::Render();
		
		SDL_RenderPresent(core.renderer);
	}

	return EXIT_SUCCESS;
}

Engine::Engine(const int width, const int height) :
	window{ nullptr }, renderer{ nullptr },
	engine_state{ false }, refresh_rate{ 0 }
{
	SDL_Log("Constructing Engine");

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
	engine_state = true;

}

Engine::~Engine()
{
	engine_spec::clear_textures();

	if (renderer) SDL_DestroyRenderer(renderer);
	SDL_Log("destroying renderer [%s]", SDL_GetError());
	
	if (window) SDL_DestroyWindow(window);
	SDL_Log("destroying window [%s]", SDL_GetError());

	renderer = nullptr;
	window = nullptr;

	SDL_Quit();

	SDL_Log("Destructing Engine");
}
