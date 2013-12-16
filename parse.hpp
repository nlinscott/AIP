#ifndef NL_PARSE_HPP
#define NL_PARSE_HPP

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

using namespace cv;


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
