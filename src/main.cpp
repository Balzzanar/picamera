/**
 * 
 * 
 */
#include <iostream>
#include "Videocaper.h" 
#include "Photocaper.h" 

struct conf {
  int action; // 0 == image, 1 == video
  std::string length;
  std::string path;
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
                if (arg == "-p") {
					i++;
					mConf.path = argv[i];
					
                } else if (arg == "-l") {
                    i++;
					mConf.length = argv[i];
					
                } else if (arg == "-a") {
                    i++;
                    std::string action = argv[i];
                    if (action == "img"){
                        mConf.action = 0;
                    } else if (action == "vid"){
                        mConf.action = 1;
                    } else {
                        mConf.action = -1;  // No action found :(
                    }
                } else {
					std::cout << "FAILED ARG: " << arg << std::endl;
			}
		}
	}
	if (mConf.action > -1 && mConf.path != "" && mConf.length != ""){
	    return true;    
	}
    return false;
}


int main(int argc, char* argv[])
{
	if (! getArgs(argc, argv)){
	    std::cout << "All needed arguments was not supplied" << std::endl;
	    return -1;
	}
//	std::cout << "Collected the following args: " << mConf.action << ", " << mConf.path << ", " << mConf.length << std::endl;


    if (mConf.action == 0){
        /* Take a photo */
        Photocaper photocaper(mConf.path);
        photocaper.take();
    } else {
        /* Record video */
        Videocaper videocaper(mConf.path, mConf.length);
        videocaper.record();
    }


	//std::cin.get(); // Just for bug windows!
	return 0;
}