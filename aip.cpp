#include "aip.hpp"


ImageIO::ImageIO(char* fileName){
	img = new Image(fileName);

	compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(1);
}
void ImageIO::splitX(char* properties){


	// if image location is invalid
	if(!img->isImageNull()){
		std::cout<< "Image not found. Check Spelling and file location. Terminating.\n";
		exit(0);
		}
	// flag lets us know when 'x' is hit, skips iteration
	bool flagx = false;

	//temporary property string
	std::string temp = properties;

	//temporary string width and height
	std::string temp_width = "";
	std::string temp_height = "";


	int i = 0;
	while (temp[i] != '\0'){
		//std::cout << temp[i] << std::endl;
		if (temp[i] == 'x'){ flagx = true; ++i; } //when 'x' is hit, it knows to start creating the height
		if (!flagx){ temp_width += temp[i]; }
		if (flagx){ temp_height += temp[i]; }
		++i;
	}
	//if x was never found -> syntax error
	if (!flagx){
		std::cout<<"Syntax Error. Dimension delimiter 'x' not found in one or more arguments. Terminating.\n";
		exit(0);
	}

	int width = atoi(temp_width.c_str()); //converts std::string to int and assigns it to each dimension
	int height = atoi(temp_height.c_str());


	//invalid width or height
	if(width == 0 || height == 0){
		std::cout << "Dimensions of all images must be greater than 0.";
		std::cout<< " Some images may have been created for valid arguments.\n";
		std::cout<< "Terminating.\n";
		exit(0);

	}else if(width > 4000 || height > 4000){
		std::cout << "Dimensions too large , use between 0 and 4000";
		std::cout<< " Some images may have been created for valid arguments.\n";
		std::cout<< "Terminating.\n";
		exit(0);
	}

	//sets the image properties
	//will be used to output a new image of WxH size
	img->setIntegerDimensions(width, height);
	img->setStringDimensions(temp_width, temp_height);



}
void ImageIO::saveNewImage(){

	Mat temp;

	std::string file = "NewImage" + img->getStringProperties() + ".png";

	//copies image to 'temp' with new size
	resize( img->getRawImage(), temp, Size(img->getWidth(), img->getHeight()), 0, 0);
	//saves temp image without overwriting original
	imwrite(file, temp, compression_params);

}
ImageIO::~ImageIO(){
	delete img;
}
Image::Image(char* fileName){

	imageFile = imread(fileName,-1);
	properties = new ImageProperties();

}
Image::~Image(){
	delete properties;
}

ImageProperties::ImageProperties(){

	setIntDimensionsProperty(0,0);
	setStringDimensionsProperty("0","0");

}
