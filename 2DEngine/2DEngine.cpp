#include <iostream>
#include "Application.h"
#include "Logger.h"

int main(int argc, char * argv[])
{
	Application myApp;
	try {
		myApp.run();
	}
	catch (std::runtime_error & error) {
		std::string the_error = error.what();
		Log<ERROR>("Runtime error thrown: " + the_error);
		return -1;
	}
    return 0;
}