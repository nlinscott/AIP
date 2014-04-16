#include "parse.hpp"

Parse::Parse(){
	//This default constructor does not work with images.
	//You must use the char* constructor.
	//This is constructor exists for syntax/semantics reasons
	int_width = 10;
	int_height = 10;
	compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(1);
}
Parse::Parse(char* imageName){
	
	image = imread(imageName,-1);
	int_width = 10;
	int_height = 10;
	compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(1);
}

void Parse::splitX(char* a){
	// if image location is invalid
	if(!image.data){
		std::cout<< "Image not found. Check Spelling and file location. Terminating.\n";
		exit(0);
		}

	bool flagx = false; // flag lets us know when 'x' is hit, skips iteration
	std::string temp = a;

	std::string temp_width;
	std::string temp_height; //temporary string width and height
	

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

		int_width = atoi(temp_width.c_str()); //converts std::string to int and assigns it to each dimension
		int_height = atoi(temp_height.c_str());
		//invalid width or height
		if(int_width == 0 || int_height == 0){
			std::cout << "Dimensions of all images must be greater than 0.";
			std::cout<< " Some images may have been created for valid arguments.\n";
			std::cout<< "Terminating.\n";
			exit(0);
		}
		if(int_width > 4000 || int_height > 4000){
					std::cout << "Dimensions too large , use between 0 and 4000";
					std::cout<< " Some images may have been created for valid arguments.\n";
					std::cout<< "Terminating.\n";
					exit(0);
				}

	str_width = temp_width; //assigns temp to private members
	str_height = temp_height; // used in file naming conventions


}

void Parse::CreateNewImage(){

	Mat temp;

	std::string img = "NewImage" + Get_str_dimensions() + ".png";



	//Resizes and saves it as a new image
	//width, height and compresion parameters are all private
		resize(image, temp, Size(int_width, int_height), 0, 0);
		imwrite(img, temp, compression_params);

}


std::ostream& operator<<(std::ostream& out, Parse a){
	out << a.Get_str_dimensions() << std::endl; // outputs width/height of Parse object.

		//cannot do " out << height;" because width and height are private
	return out;
}
