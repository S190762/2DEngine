#pragma once
#include <SDL.h>

class Window_SDL {
protected:
	SDL_Window * window;
	SDL_Event event;
public:
	Window_SDL(const char * title, int w, int h, int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED);
	SDL_Window * getWindowPtr();
	bool processEvents();
	Uint32 getEventType();
	bool isWindowClosed();
};
