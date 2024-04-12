#include "handler.h"

#include "engine_spec.h"

Handler::Handler(EngineDef* engine) :
	Input { engine->InputSystem },
	Texture { engine->TextureSystem }
{

}