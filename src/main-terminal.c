#include "main-terminal.h"

int main(int argc, const char* argv[]){
//TODO Wypierdolic wszystko czego nie trzeba bezposrednio do oddzielnych funkcji i tylko je callowac w mainie. Bo sie main kosmicznie rozrośnie
	std::cout<<"Welcome to KODA PROJECT number 2\n";
	while(true){
		std::cout<<"For Huffman static algorithm coder, press 1\n";
		std::cout<<"For Huffman dynamic algorithm coder, press2\n"<<"For Huffman dynamic algorithm decoder, press 3\n";
		std::cout<<"For file generator with chosen characteristic, press 4\n"<<"To exit, press 0\n";
		int chosenOption = 0;
		std::cin>>chosenOption;
		//check if input value was correct - that is integer
		if(!std::cin){
			std::cout<<"\n"<<"The option you chose IS NOT A NUMBER. Please read all available options and choose again.\n";
			//clear input stream of failbit and value
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		switch(chosenOption){
			case HUFFMAN_STATIC_CODER:
			//call the proper function

			return 0;

			case HUFFMAN_DYNAMIC_CODER:
			//call the proper function

			return 0;

			case HUFFMAN_DYNAMIC_DECODER:
			//call the proper function

			return 0;

			case FILE_GENERATOR:
			//call the proper function
			
			return 0;

			case EXIT:
			return 0;

			default:
			std::cout<<"\n"<<"The option you chose does not exist. Please read all available options and choose again.\n";
			continue;
		}
	}
	
}
