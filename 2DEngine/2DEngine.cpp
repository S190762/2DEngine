#include <iostream>
#include "Application.h"

int main(int argc, char * argv[])
{
	Application myApp;
	try {
		myApp.run();
	}
	catch (std::runtime_error & error) {
		std::cout << "Runtime error: " << error.what() << std::endl;
		return -1;
	}
    return 0;
}