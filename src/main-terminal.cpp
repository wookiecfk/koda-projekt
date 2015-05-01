#include "main-terminal.h"
#include "static/huffman.h"

void info()
{
	std::cout << "Huffman.exe nazwa_pliku akcja\n";
	std::cout << "Akcja:\n";
	std::cout << "\t1 - Koder statyczny Huffmana\n"
		<< "\t2 - Dekoder statyczny Huffmana\n"
		<< "\t3 - Adaptacyjny koder Huffmana\n"
		<< "\t4 - Adaptacyjny dekoder Huffmana\n";
}

int main(int argc, const char* argv[]){

	if(argc != 3)
	{
		info();
		return 0;
	}
	
	std::string  fileName = (std::string)argv[1];
	int chosenOption = atoi(argv[2]);
		
	switch(chosenOption){
			case HUFFMAN_STATIC_CODER:
				if(staticCoder(fileName))
					std::cout << "Kodowanie zakonczone.";
				else
					std::cout << "Kodowanie nie powiodlo sie!";
				break;

			case HUFFMAN_STATIC_DECODER:
				if(staticDecoder(fileName))
					std::cout << "Dekodowanie zakonczone.";
				else
					std::cout << "Dekodowanie nie powiodlo sie!";
				break;

			case HUFFMAN_DYNAMIC_CODER:
			//call the proper function

			break;

			case HUFFMAN_DYNAMIC_DECODER:
			//call the proper function

			break;

			case FILE_GENERATOR:
			//call the proper function
			
			break;

			case EXIT:
			break;

			default:
				info();
				break;
	}
	return 0;
}
	

