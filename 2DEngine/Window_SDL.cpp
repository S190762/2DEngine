#include "Window_SDL.h"
#include "Logger.h"
#include <string>

Window_SDL::Window_SDL(const char * title, int w, int h, int x /*= SDL_WINDOWPOS_CENTERED*/, int y /*= SDL_WINDOWPOS_CENTERED*/)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) < 0) {
		throw std::runtime_error("Failed to initialize SDL");
	}
	window = SDL_CreateWindow("2D Engine", x, y, w, h, NULL);
	if (!window) {
		throw std::runtime_error("Failed to create an SDL window");
	}
	else {
		Log<SYSTEM_INIT>("Created SDL Window");
	}
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
