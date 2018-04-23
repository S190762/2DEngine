#include "Window_SDL.h"

Window_SDL::Window_SDL(const char * title, int w, int h, int x /*= SDL_WINDOWPOS_CENTERED*/, int y /*= SDL_WINDOWPOS_CENTERED*/)
{
	window = SDL_CreateWindow("2D Engine", x, y, w, h, NULL);
}

SDL_Window * Window_SDL::getWindowPtr()
{
	return window;
}

bool Window_SDL::processEvents()
{
	return SDL_PollEvent(&event);
}

Uint32 Window_SDL::getEventType()
{
	return event.type;
}

bool Window_SDL::isWindowClosed()
{
	return getEventType() == SDL_QUIT;
}
