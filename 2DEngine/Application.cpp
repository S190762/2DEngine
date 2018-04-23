#include "Application.h"
#include "Logger.h"

void menu_event() {
	Log<INFO>("Menu pressed, event 1");
}

Application::Application()
{
	window = new Window_SDL("2D Game Engine", 800, 600);
	renderer = new Renderer_SDL(window);
	imanager = new InputManager();
	imanager->addEvent(MENU, menu_event);
}

void Application::run()
{
	while (running) {
		while (window->processEvents()) {
			if (window->isWindowClosed()) running = false;
			imanager->processEvents(window->getEvent());
		}
		renderer->clear(25, 50, 75);
		
		renderer->present();
	}
}
