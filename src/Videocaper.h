/**
 * Videocaper
 * 
 * Class for recording a video on the raspberry pi.
 * 
 * Will run the command for recording a new video for
 * the given length. And as soon as the recording is done
 * the video is converted to .mp4 from .h264. This is 
 * done with '&'. So that the camera can continue to
 * record. 
 * 
 */
#ifndef VIDEO_H_
#define VIDEO_H_

class Videocaper
{
private:
    std::string mPath;
    std::string mName;
    std::string mNameConv;
    std::string mLength;
    void convert();
    const std::string currentDateTime();
    void genname();
public:
	Videocaper(std::string path, std::string length);
	void record(bool loop, int looplength);
};

#endif /* VIDEO_H_ */