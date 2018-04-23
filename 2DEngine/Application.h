#pragma once
#include "Window_SDL.h"
#include "Renderer_SDL.h"

class Application {
protected:
	Window_SDL * window;
	Renderer_SDL * renderer;
	bool running = true;
public:
	Application();
	void run();
};