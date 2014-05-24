#ifndef NL_AIP_HPP
#define NL_AIP_HPP

/******************Side Notes ***************/
/* Compiler used for testing, building: Cygwin
 * Uses OpenCV for Windows 2.4.7
 *
 *  //// Developer: Nic Linscott ////
 *
 *
 *
 *
 *
 */


#include <opencv\cv.h>
#include <opencv2\highgui\highgui.hpp>


#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace cv;


class ImageProperties{

public:
	ImageProperties();

	void setIntDimensionsProperty(int x, int y){ width = x; height = y;  };
	void setStringDimensionsProperty(std::string x, std::string y){ str_width = x; str_height = y; };

	std::string getStringDimensions(){ return str_width + "x" + str_height; };
	int getImageHeight(){ return height; };
	int getImageWidth(){ return width; };

private:

	//integer dimensions used for resizing
	//string dimensions used for naming output file
	int width;
	int height;
	std::string str_width;
	std::string str_height;


};

class Image{
public:
	Image():properties(0){};
	Image(char*);

	~Image();

	void setIntegerDimensions(int x, int y){ properties->setIntDimensionsProperty(x, y); };
	void setStringDimensions(std::string x, std::string y){ properties->setStringDimensionsProperty(x, y); };

	std::string getStringProperties(){ return properties->getStringDimensions(); };
	int getHeight(){ return properties->getImageHeight(); };
	int getWidth(){ return properties->getImageWidth(); };

	bool isImageNull(){ return imageFile.data; };
	Mat getRawImage(){ return imageFile; };
private:

	ImageProperties* properties;
	Mat imageFile;
};


class ImageIO{

public:
	ImageIO(): img(0){};
	ImageIO(char*);

	~ImageIO();

	void saveNewImage();
	void splitX(char*);

private:

	vector<int> compression_params; //default is PNG compression
	Image* img;

};




#endif /* NL_AIP_HPP */
