#include "parse.hpp"



int main(int argc, char* argv[]){
	//argv[0] should be AIP
	//argv[1] should be the image you want to duplicate
	//argv[2....n] should be dimensions
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
	Parse b(argv[1]);
	int i = 2;

		while (argv[i] != '\0'){
			
			b.splitX(argv[i]);  //argv[1],2,3... i

			try{
				b.CreateNewImage();
			}catch(Exception& ex){
				std::cout << ex.what();
				std::cout << "\n\n";
				std::cout << "No files were created due to an internal OpenCV error.\n";
				exit(0);
			}

		++i;
		}
	}
	return 0;

}




