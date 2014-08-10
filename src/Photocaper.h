/**
 * Photocaper
 * 
 * Class for taking a photo on the raspberry pi.
 * 
 * 
 */
#ifndef PHOTO_H_
#define PHOTO_H_

class Photocaper
{
private:
    std::string mPath;
    std::string mName;
    const std::string currentDateTime();
    std::string genname();
public:
	Photocaper(std::string path);
	void take(bool loop, int looplength);
};

#endif /* PHOTO_H_ */