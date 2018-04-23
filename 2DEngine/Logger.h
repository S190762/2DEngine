#pragma once
#include <iostream>
#include <string>

enum logger_type {
	DEBUG,
	SYSTEM_INIT,
	DESTROY,
	OTHER,
	WARNING,
	ERROR,
	INFO,
	ENGINE_MSG
};

std::string get_label(logger_type type);

template<logger_type T = INFO>
void Log(std::string message)
{
	std::cout << "[" << get_label(T) << "] " << message << std::endl;
}
