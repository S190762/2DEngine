#include "Logger.h"

std::string get_label(logger_type type)
{
	std::string label;
	switch (type) {
	case DEBUG: label = "DEBUG"; break;
	case SYSTEM_INIT: label = "SYSTEM INIT"; break;
	case DESTROY: label = "DESTROY"; break;
	case OTHER: label = "OTHER"; break;
	case WARNING: label = "WARNING"; break;
	case ERROR: label = "ERROR"; break;
	case ENGINE_MSG: label = "ENGINE MSG"; break;
	case INFO: label = "INFO"; break;
	default: label = "NO LABEL"; break;
	}
	return label;
}

