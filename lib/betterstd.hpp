#ifndef NOT_BETTER_STD
#define NOT_BETTER_STD

#include "text/print.hpp"
#include "system/exit.hpp"


int main();
extern "C" void _start() {
	exit(main());
}

#endif
