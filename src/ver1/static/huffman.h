#include <string>
#include <iostream>

int staticCoder(std::string fileName);

/** Liczy prawdopodobienstwo wystapienia poszczegolnych elementow.
	
	@param[in]    fileSize rozmiar wczytanego pliku w bajtach
	@param[in]    dataPtr wskaznik do danych z pliku wczytanych do pamieci
	@param[out]   prob wskaznik do tablicy z prawdopodobienstwem wystapienia poszczegolnych elementow */
void countProb(int &fileSize, unsigned char *dataPtr, int *prob);

int staticDecoder(std::string fileName);