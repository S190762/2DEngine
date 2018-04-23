#include "Application.h"

Application::Application()
{
	window = new Window_SDL("2D Game Engine", 800, 600);
	renderer = new Renderer_SDL(window);
}

void Application::run()
{
	while (running) {
		while (window->processEvents()) {
			if (window->isWindowClosed()) running = false;
		}
		renderer->clear(0, 0, 0);
		renderer->present();
	}
}
