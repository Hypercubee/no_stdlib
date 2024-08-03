#include "lib/betterstd.hpp"




int main(){

	char buff[20];

	print("hello\n");
	toString(-12345, buff);
	print(buff);
	print("\n");

	toString(0.5f, buff);
	print(buff);
	print("\n");

	toString(253.578, buff);
	print(buff);
	print("\n");

	return 0;
}
