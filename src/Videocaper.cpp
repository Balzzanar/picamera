#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "Videocaper.h"

/** Collects a timestamp for the image, that shall be used in the image name */
const std::string Videocaper::currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

/** Generates a name for the video */
std::string Videocaper::genname(){
    std::string format= ".h264";
    std::string formatConv= ".mp4";
    mName = "vid_"+currentDateTime(); 
    mNameConv = mName+formatConv;
    mName = mName+format;
}

/** Converts the newly recorded video from .h264 to .mp4 */
void Videocaper::convert(){
    //... shall start the video convertion
    // "MP4Box -add filename.h264 filename.mp4"
    std::string cmd = "MP4Box -add";
    cmd=cmd+" "+mPath+mName+" "+mPath+mNameConv;
    std::cout << "Command: " << cmd << std::endl;
}

/** Constructor */
Videocaper::Videocaper(std::string path, std::string length){
    mPath   = path;
    mLength = length;
}

/** Starts the recording with the given length, and the given path, waits for it to finnish */
void Videocaper::record(){
    genname();
    std::string cmd = "raspvid";
    cmd=cmd+" -o "+mPath+mName;
    cmd=cmd+" -t "+mLength+"000";
    std::cout << "Command: " << cmd << std::endl;
    convert();
}

