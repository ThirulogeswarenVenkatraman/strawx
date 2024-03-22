#include "input.h"

using namespace strawx;

InputHandler::InputHandler() : keystate{ nullptr }
{
	this->repeat.fill(0);
}

InputHandler::~InputHandler()
{
	keystate = nullptr;
}