#include "aip.hpp"



int main(int argc, char* argv[]){

	if(strcmp(argv[1], "-help") == 0){
		std::cout<< "\nExample Syntax:\n";
		std::cout<< "AIP test.jpg 210x300 400x400 150x150\n";
		std::cout<< "Command list: AIP -help, AIP -abi\n";
		std::cout<< "Refer to https://github.com/nlinscott/AIP for more documentation.\n";
		exit(0);
	}
	///////
	//
	// CASE 1
	//
	///////

	//argv[0] should be AIP
	//argv[1] should be the image you want to duplicate
	//argv[2....n] should be dimensions
	//std::cout << argv[0] << argv[1] << argv[2] << std::endl;

	//////
	//
	// CASE 2
	//
	//////

	//Implement a command '-abi' to get an
	// image for each dpi in the Resources directory
	// -abi == action bar icon
	//argv[0] should be AIP
	//argv[1] should be the image you want to duplicate
	//argv[2] should be -abi
	//std::cout << argv[0] << argv[1] << argv[2] << std::endl;


	if(argc < 3){
		std::cout<< "Error!\n";
		std::cout<< "Not enough parameters specified.\n";
		std::cout<< "Must have AIP, then the image location, then dimensions.\n";
		std::cout<< "Dimensions for this prototype must be within 0 and 4000.\n";
		std::cout<< "Example Syntax:\n";
		std::cout<< "AIP test.jpg 210x300 400x400 150x150\n";
		exit(0);
	}else{

		if(strcmp(argv[2], "-abi") == 0){

			AndroidDPI logo(argv[1]);

			try{
				logo.generateLogos();
			}catch(Exception& ex){
				std::cout << ex.what();
				std::cout << "\n\n";
				std::cout << "No files were created due to an internal OpenCV error.\n";
				exit(0);
			}

		}else{

			ImageIO img(argv[1]);

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
	}




	return 0;

}




