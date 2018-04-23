#pragma once
#include <SDL.h>
#include "Window_SDL.h"

class Renderer_SDL {
protected:
	SDL_Renderer * renderer;
public:
	Renderer_SDL(Window_SDL * window);
	~Renderer_SDL();
	void clear(Uint8 r, Uint8 g, Uint8 b, Uint8 a = SDL_ALPHA_OPAQUE);
	void present();
};