/**
 * 
 * 
 */
#include <iostream>
#include "Videocaper.h" 
#include "Photocaper.h" 

struct Conf {
  int action;          // 0    == image, 1 == video
  bool loop;           // will loop and continue with the actions
  int looplength = 7;  // length of each loop
  std::string length;  // length of the video (sec)
  std::string path;    // path to store the result
};

/**
 * Collects all the arguments for the program.
 */
bool getArgs(int argc, char* argv[], Conf *mConf){
	std::cout << "Arguments: " << argc << std::endl;
	std::string myFile, myPath, myOutPath;
	mConf->loop = false;

	for (int i = 1; i < argc; i++) {
		if (i + 1 != argc) {	// Check that we haven't finished parsing already
			std::string arg = argv[i];
			std::cout << "VAR: " << arg << std::endl;
                if (arg == "-p") {
					i++;
					mConf->path = argv[i];
					
                } else if (arg == "-l") {
                    i++;
					mConf->length = argv[i];
					
                } else if (arg == "-a") {
                    i++;
                    std::string action = argv[i];
                    if (action == "img"){
                        mConf->action = 0;
                    } else if (action == "vid"){
                        mConf->action = 1;
                    } else {
                        mConf->action = -1;  // No action found :(
                    }
                
                } else if (arg == "-loop") {
                    
		            mConf->loop = true;
                    
                } else {
					std::cout << "FAILED ARG: " << arg << std::endl;
			}
		}
	}
	if (mConf->action > -1 && mConf->path != "" && mConf->length != ""){
	    return true;    
	}
    return false;
}



int main(int argc, char* argv[])
{
    Conf sConf;
    Conf *mConf = &sConf;
	if (! getArgs(argc, argv, mConf)){
	    std::cout << "All needed arguments was not supplied" << std::endl;
	    return -1;
	}
//	std::cout << "Collected the following args: " << mConf->action << ", " << mConf->path << ", " << mConf->length << std::endl;

    if (mConf->action == 0){
        /* Take a photo */
        Photocaper photocaper(mConf->path);
        photocaper.take(mConf->loop, mConf->looplength);
    } else {
        /* Record video */
        Videocaper videocaper(mConf->path, mConf->length);
        videocaper.record(mConf->loop, mConf->looplength);
    }


	//std::cin.get(); // Just for bug windows!
	return 0;
}