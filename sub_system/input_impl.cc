#include "input.h"

#define INCLUDING_COMMON_SPEC__CH
#include "shared/spec__c.h"

using namespace strawx;

bool InputHandler::IsKeyDown(SDL_Scancode scancode)
{
	return KeyboardStates.state[scancode];
}

bool InputHandler::IsKeyReleased(SDL_Scancode scancode)
{
	return KeyboardStates.up[scancode];
}

bool InputHandler::IsKeyPressed(SDL_Scancode scancode)
{
	if (KeyboardStates.down[scancode] && (!KeyboardStates.repeat[scancode])) {
		KeyboardStates.repeat[scancode] = 1;
		return true;
	}
	return false;
}
