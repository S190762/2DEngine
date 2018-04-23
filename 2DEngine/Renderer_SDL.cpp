#include "Renderer_SDL.h"
#include "Logger.h"
#include <stdexcept>

Renderer_SDL::~Renderer_SDL()
{
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
}

void Renderer_SDL::clear(Uint8 r, Uint8 g, Uint8 b, Uint8 a /*= SDL_ALPHA_OPAQUE*/)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderClear(renderer);
}

void Renderer_SDL::present()
{
	SDL_RenderPresent(renderer);
}

Renderer_SDL::Renderer_SDL(Window_SDL * window)
{
	renderer = SDL_CreateRenderer(window->getWindowPtr(), -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		throw std::runtime_error("Failed to create a SDL renderer!");
	}
	else {
		Log<SYSTEM_INIT>("Created SDL Renderer");
	}
}
