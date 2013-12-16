#ifndef NL_PARSE_HPP
#define NL_PARSE_HPP


#include <opencv\cv.h>
#include <opencv2\highgui\highgui.hpp>

using namespace cv;
/***************** IMPORTANT *********************/

//The OpenCV include paths are strange because of the way I set it up in MSVS 2013 pro.
//You will have to change for other compilers, setups and directories
//Just google how to do this. You must install OpenCV, set a system variable and path (windows)
//and set additional dependencies in Visual Studio (not sure about other compilers, though. Sorry)

/************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace cv;


class Parse{
public:
	Parse();
	Parse(char*);

	void splitX(char*);

	void CreateNewImage(char);

	std::string Get_str_dimensions(){ return str_width + "x" + str_height; };

	friend std::ostream& operator<<(std::ostream&, Parse&);

private:

	//integer dimensions used for resizing
	//string dimensions used for naming output file
	int int_width;
	int int_height;
	std::string str_width; 
	std::string str_height;


	Mat image;
};



#endif /* NL_PARSE_HPP */
