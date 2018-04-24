#pragma once
#include "Window_SDL.h"
#include "Renderer_SDL.h"
#include "InputManager.h"
#include "ResourceManager.h"

class Application {
protected:
	Window_SDL * window;
	Renderer_SDL * renderer;
	InputManager * imanager;
	ResourceManager * rmanager;
	bool running = true;
public:
	Application();
	void run();
};