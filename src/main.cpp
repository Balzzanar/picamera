#include <iostream>
#include "example.h"  // defines MyClass

struct conf {
  int action;
  std::string filepath;
  std::string path;
  std::string output;
} mConf;

/**
 * Collects all the arguments for the program.
 */
bool getArgs(int argc, char* argv[]){
	std::cout << "Arguments: " << argc << std::endl;
	std::string myFile, myPath, myOutPath;
	
	for (int i = 1; i < argc; i++) {
		if (i + 1 != argc) {	// Check that we haven't finished parsing already
			std::string arg = argv[i];
                if (arg == "-f") {
                    // We know the next argument *should* be the filename:
					i++;
					myFile = argv[i];
					mConf.filepath = myFile;
					
                } else if (arg == "-p") {
                    i++;
					myPath = argv[i];
					mConf.path = myPath;
					
                } else if (arg == "-o") {
                    i++;
					myOutPath = argv[i];
					mConf.output = myOutPath;
					
                } else {
					std::cout << "FAILED ARG: " << arg << std::endl;
			}
		}
	}
	if (mConf.filepath != "" && mConf.path != "" && mConf.output != ""){
	    return true;    
	}
    return false;
}


int main(int argc, char* argv[])
{
	int ACTION = 0;
	example a; // no longer produces an error, because MyClass is defined
	std::cout << "And we are all done!" << std::endl;
	a.foo();
	
	std::cout << "We are getting starting with id: " << a.getID() << std::endl;

	if (! getArgs(argc, argv)){
	    std::cout << "Failed at getting the args";
	}
	std::cout << "Collected the following args: " << mConf.filepath << ", " << mConf.path << ", " << mConf.output << std::endl;
	
	std::cin.get(); // Just for bug windows!
	return 0;
}