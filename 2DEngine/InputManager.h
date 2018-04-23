#pragma once
#include <SDL.h>
#include <functional>
#include <map>
#include <vector>

enum input_type {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	ACTION,
	JUMP,
	MENU
};

using InputCallback = std::function<void()>;
using InputCallbacks = std::vector<InputCallback>;

class InputManager {
protected:
	std::map<input_type, InputCallbacks> callbacks;
public:
	void addEvent(input_type t, InputCallback c) {
		callbacks[t].push_back(c);
	}
	void processEvents(SDL_Event & event) {
		for (auto cbs : callbacks) {
			InputCallbacks types = cbs.second;
			if (event.key.type == SDL_KEYDOWN) {
				switch (cbs.first) {
				case UP: {
					if (event.key.keysym.sym == SDLK_UP) {
						for (auto callback : types) {
							callback();
						}
					}
					break;
				}
				case DOWN: {
					if (event.key.keysym.sym == SDLK_DOWN) {
						for (auto callback : types) {
							callback();
						}
					}
					break;
				}
				case LEFT: {
					if (event.key.keysym.sym == SDLK_LEFT) {
						for (auto callback : types) {
							callback();
						}
					}
					break;
				}
				case RIGHT: {
					if (event.key.keysym.sym == SDLK_RIGHT) {
						for (auto callback : types) {
							callback();
						}
					}
					break;
				}
				case ACTION: {
					if (event.key.keysym.sym == SDLK_e) {
						for (auto callback : types) {
							callback();
						}
					}
					break;
				}
				case JUMP: {
					if (event.key.keysym.sym == SDLK_SPACE) {
						for (auto callback : types) {
							callback();
						}
					}
					break;
				}
				case MENU: {
					if (event.key.keysym.sym == SDLK_ESCAPE) {
						for (auto callback : types) {
							callback();
						}
					}
					break;
				}
				}
			}
		}
	}
};