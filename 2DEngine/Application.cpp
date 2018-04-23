#include "Application.h"
#include "Logger.h"

enum resource_type {
	SPRITE,
	SOUND,
	MUSIC
};

struct resource_field {
	resource_type t;
	void * data;
};

struct Sprite {
	int width;
	int height = 25;
	int xpos;
	int ypos;
};

struct Sound {
};

class ResourceManager {
private:
	std::map<resource_type, std::map<std::string, resource_field>> resources;
public:
	template<resource_type rt>
	void addResource(std::string id, void * data) {
		resource_field res;
		res.t = rt;
		res.data = data;
		resources[rt].insert(std::pair<std::string, resource_field>(id, res));
	}
	Sprite * getSprite(std::string id) {
		return reinterpret_cast<Sprite*>(resources[SPRITE][id].data);
	}
	Sound * getSound(std::string id) {
		return reinterpret_cast<Sound*>(resources[SOUND][id].data);
	}
};


void menu_event() {
	Log<INFO>("Menu pressed, event 1");
}

Application::Application()
{
	window = new Window_SDL("2D Game Engine", 800, 600);
	renderer = new Renderer_SDL(window);
	imanager = new InputManager();
	imanager->addEvent(MENU, menu_event);
	ResourceManager * rm = new ResourceManager();
	Sprite * sp = new Sprite();
	rm->addResource<SPRITE>("player", sp);
	std::cout << rm->getSprite("player")->height << std::endl;
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
