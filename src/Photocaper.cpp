#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "Photocaper.h"

/** Collects a timestamp for the image, that shall be used in the image name */
const std::string Photocaper::currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

/** Generates a name for the image */
std::string Photocaper::genname(){
    std::string format= ".jpg";
    return currentDateTime()+format;
}

/** Constructor */
Photocaper::Photocaper(std::string path){
    mPath = path;
}

/** Takes the actual photo and places it in the propper file path */
void Photocaper::take(){
    std::cout << "mPath= " << mPath << "genname= " << genname() << std::endl;
}

