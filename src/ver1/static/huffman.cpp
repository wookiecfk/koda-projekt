#include "huffman.h"

extern int readFile (std::string &fileName, int &fileSize, unsigned char *&dataPtr);

int staticCoder(std::string fileName)
{
	int fileSize = 0;			//rozmiar pliku
	unsigned char *dataPtr;		//wskaznik do pliku
	int *prob = new int[256](); //wskaznik do tablicy z p-stwem

	if(!readFile(fileName, fileSize, dataPtr))
	{
		std::cout << "Nie mozna wczytac pliku!" <<std::endl;
		return 0;
	}
	
	//Liczenie prawdopodobienstwa
	countProb(fileSize, dataPtr, prob);

	delete[] dataPtr;
	delete[] prob;
	return 1;
}

void countProb(int &fileSize, unsigned char *dataPtr, int *prob)
{
	for(int i = 0; i < fileSize; i++)
		prob[dataPtr[i]]++;

	//wyswietlanie pstwa
	/*int count = 0;
	for(int i=0;i<256; i++)
		std::cout << prob[i] << " ";
	std::cout<<"count: " << count << std::endl;*/
}

int staticDecoder(std::string fileName)
{
	return 1;
}