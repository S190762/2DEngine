#pragma once
#include <string>
#include <vector>
#include <map>

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
	void addResource(std::string id, void * data);
	Sprite * getSprite(std::string id);
	Sound * getSound(std::string id);
};

template<resource_type rt>
void ResourceManager::addResource(std::string id, void * data)
{
	resource_field res;
	res.t = rt;
	res.data = data;
	resources[rt].insert(std::pair<std::string, resource_field>(id, res));
}
