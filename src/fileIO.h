#include <iostream>
#include <fstream>
#define dictionarySize 256


/** Wczytuje plik do pamieci dynamicznej.
	
	@param[in]     fileName nazwa pliku do wczytania
	@param[out]    fileSize rozmiar wczytanego pliku w bajtach
	@param[out]    dataPtr wskaznik do danych z pliku wczytanych do pamieci
		
  	@retval        1 w przypadku poprawnego wczytania
  	@retval        0 w przypadku bledu */
int readFile (std::string &fileName, int &fileSize, unsigned char *&dataPtr);

/** Wczytuje plik do pamieci dynamicznej.
	
	@param[in]     fileName nazwa pliku do zapisania
	@param[out]    fileSize rozmiar zapisanego pliku w bajtach
	@param[out]    dataPtr wskaznik do danych do zapisania w plikus
		
  	@retval        1 w przypadku poprawnego wczytania
  	@retval        0 w przypadku bledu  */
int writeFile (std::string &fileName, int &fileSize, unsigned char *&dataPtr);

int writeDictionary (std::string &fileName, std::string *fileContent);
