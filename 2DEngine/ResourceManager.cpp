#include "ResourceManager.h"

Sprite * ResourceManager::getSprite(std::string id)
{
	return reinterpret_cast<Sprite*>(resources[SPRITE][id].data);
}

Sound * ResourceManager::getSound(std::string id)
{
	return reinterpret_cast<Sound*>(resources[SOUND][id].data);
}
