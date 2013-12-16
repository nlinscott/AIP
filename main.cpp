#include "parse.hpp"



int main(int argc, char* argv[]){
	char* a = "320x210"; //argv[1],2,3... i
	Parse b("yell.jpg");
	int i = 0;
		while (/*argv[i] != '\0'*/ i < 1){
			
			b.splitX(a);  //argv[1],2,3... i

	
			b.CreateNewImage(char(i));

		
		++i;
		}

	return 0;
}

