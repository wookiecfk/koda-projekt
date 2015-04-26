#include <string>
#include <iostream>
#include "huffmanType.h"

int staticCoder(std::string fileName);

/** Liczy prawdopodobienstwo wystapienia poszczegolnych elementow.
	
	@param[in]    fileSize rozmiar wczytanego pliku w bajtach
	@param[in]    dataPtr wskaznik do danych z pliku wczytanych do pamieci
	@param[out]   prob wskaznik do tablicy z prawdopodobienstwem wystapienia poszczegolnych elementow */
void countProb(int &fileSize, unsigned char *dataPtr, int *prob);

void buildTree(node *&tree, int *&prob);

int findSubtree(node *nodes[], int val, int sign);

void createCodes(std::string codedSymbols[], node *tree, std::string codedSeq);

int staticDecoder(std::string fileName);