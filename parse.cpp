#include "parse.hpp"

Parse::Parse(){

	int_width = 0;
	int_height = 0;
}
Parse::Parse(char* imageName){
	
	image = imread(imageName,1);
	int_width = 0;
	int_height = 0;
}

void Parse::splitX(char* a){
	bool flagx = false; // flag lets us know when 'x' is hit, skips iteration
	std::string temp = a;

	std::string temp_width;
	std::string temp_height; //string width and height
	

	int i = 0;
	while (temp[i] != '\0'){
		//std::cout << temp[i] << std::endl;
		if (temp[i] == 'x'){ flagx = true; ++i; } //when 'x' is hit, it knows to start creating the height
		if (!flagx){ temp_width += temp[i]; }
		if (flagx){ temp_height += temp[i]; }
		++i;
	}
	str_width = temp_width;
	str_height = temp_height;

	int_width = atoi(temp_width.c_str()); //converts std::string to int and assigns it to each dimension
	int_height = atoi(temp_height.c_str());
}

void Parse::CreateNewImage(char i){
	Mat temp;
	std::string img = i + "NewImage" + Get_str_dimensions();

	//PNG compression parameters
	vector<int> compression_params;
	compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
	
	//Resizes and saves it as a new image
		resize(image, temp, Size(int_width, int_height), 0, 0);
		imwrite(img, temp, compression_params);
	
}


std::ostream& operator<<(std::ostream& out, Parse a){
	out << a.Get_str_dimensions() << std::endl; // outputs width/height of Parse object.

		//cannot do " out << height;" because width and height are private
	return out;
}
