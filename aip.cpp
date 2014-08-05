#include "aip.hpp"

AndroidDPI::AndroidDPI(char* filePath, std::string name){

	logo = new ImageIO(filePath);
	imageName = name;
	mdpi = 32;
	hdpi = 48;
	xhdpi = 64;
	xxhdpi = 96;
	dir_mdpi = "drawable-mdpi\\";
	dir_hdpi = "drawable-hdpi\\";
	dir_xhdpi = "drawable-xhdpi\\";
	dir_xxhdpi = "drawable-xxhdpi\\";
}

void AndroidDPI::generateLogos(){

		logo->saveLogo(mdpi, concatenateFilePath(dir_mdpi));
		logo->saveLogo(hdpi, concatenateFilePath(dir_hdpi));
		logo->saveLogo(xhdpi, concatenateFilePath(dir_xhdpi));
		logo->saveLogo(xxhdpi, concatenateFilePath(dir_xxhdpi));
}

std::string AndroidDPI::concatenateFilePath(std::string dir){
	if( doesDirExist(dir) ){
		std::string outPath = dir + imageName;
		//std::cout << outPath + "\n\n";
		return outPath;
	}else{
		std::cout << "Cannot find '" << dir << "'. The -abi command must be used within an Android res folder.\n";
		exit(0);
	}

}

bool AndroidDPI::doesDirExist(std::string dir){

	DWORD fileType = GetFileAttributes(dir.c_str());
	if (fileType == INVALID_FILE_ATTRIBUTES){
	    //invalid path
		return false;
	}else if(fileType & FILE_ATTRIBUTE_DIRECTORY){
		//drawable-* directory exists
	    return true;
	}

	return false;
}

AndroidDPI::~AndroidDPI(){
	if(logo)delete logo;
}

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
	//if x was never found = syntax error
	if (!flagx){
		std::cout<<"Syntax Error. Dimension delimiter 'x' not found in one or more arguments.\n\n Did you mistype a command? Type AIP -help for syntax. Terminating.\n";
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
		std::cout << "Dimensions too large, use between 0 and 4000.";
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

void ImageIO::saveLogo(const int res, std::string outFile){
	Mat temp;

	//copies image to 'temp' with new size
	resize( img->getRawImage(), temp, Size(res,res), 0, 0);
	//saves temp image without overwriting original
	imwrite(outFile, temp, compression_params);

}

ImageIO::~ImageIO(){
	if(img) delete img;
}

Image::Image(char* fileName){

	imageFile = imread(fileName,-1);
	properties = new ImageProperties();

}

Image::~Image(){
	if(properties) delete properties;
}

ImageProperties::ImageProperties(){

	setIntDimensionsProperty(0,0);
	setStringDimensionsProperty("0","0");

}

