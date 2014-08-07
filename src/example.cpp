#include <iostream>
#include "example.h"


example::example(){
	id = 15;
}
void example::foo(){
	std::cout << "hejsan from example" << std::endl;
}
int example::getID(){
		return id;
}


