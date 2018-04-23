#include "Renderer_SDL.h"

Renderer_SDL::~Renderer_SDL()
{
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	delete renderer;
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
}
