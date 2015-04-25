#include <iostream>
#include <fstream>


/** Wczytuje plik do pamieci dynamicznej.
	
	@param[in]     fileName nazwa pliku do wczytania
	@param[out]    fileSize rozmiar wczytanego pliku w bajtach
	@param[out]    dataPtr wskaznik do danych z pliku wczytanych do pamieci
		
  @retval        1 w przypadku poprawnego wczytania
  @retval        0 w przypadku bledu */
int readFile (std::string &fileName, int &fileSize, unsigned char *&dataPtr);
