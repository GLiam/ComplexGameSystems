#include "GASystemApp.h"

int main() {
	
	// allocation
	auto app = new GASystemApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}