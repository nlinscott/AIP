#include "aip.hpp"



int main(int argc, char* argv[]){

	///////
	//
	// CASE 1
	//
	///////

	//argv[0] should be AIP
	//argv[1] should be the image you want to duplicate
	//argv[2....n] should be dimensions
	//std::cout << argv[0] << argv[1] << argv[2] << std::endl;


	ImageIO img(argv[1]);

	if(argc < 3){
		std::cout<< "Error!\n";
		std::cout<< "Not enough parameters specified.\n";
		std::cout<< "Must have AIP, then the image location, then dimensions.\n";
		std::cout<< "Dimensions for this prototype must be within 0 and 4000.\n";
		std::cout<< "Example Syntax:\n";
		std::cout<< "AIP test.jpg 210x300 400x400 150x150\n";
		exit(0);
	}else{

		int i = 2;

		while (argv[i] != '\0'){

			img.splitX(argv[i]);

			try{
				img.saveNewImage();
			}catch(Exception& ex){
				std::cout << ex.what();
				std::cout << "\n\n";
				std::cout << "No files were created due to an internal OpenCV error.\n";
				exit(0);
			}
			++i;
		}
	}

	//////
	//
	// CASE 2
	//
	//////

	//TODO:
	//Implement a command 'all' to get an
	// image for each dpi in the Resources directory


	return 0;

}




