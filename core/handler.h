#ifndef STRAWX_ENGINE_HANDLERS_HH
#define STRAWX_ENGINE_HANDLERS_HH

#include "input_handler.h"
#include "texture.h"

class Handler final
{
public:
	inline static Handler* e_handler{ nullptr };

	InputHandler&		Input;
	TextureManager&		Texture;

private:
	friend struct EngineDef;

	Handler(EngineDef* engine);
};

#define Handlers Handler::e_handler

#endif
