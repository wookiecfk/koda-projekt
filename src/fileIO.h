#include <iostream>
#include <fstream>
#include <map>
#include <boost/dynamic_bitset.hpp>
#define dictionarySize 256


/** Wczytuje plik do pamieci dynamicznej.
	
	@param[in]     fileName nazwa pliku do wczytania
	@param[out]    fileSize rozmiar wczytanego pliku w bajtach
	@param[out]    dataPtr wskaznik do danych z pliku wczytanych do pamieci
		
  	@retval        1 w przypadku poprawnego wczytania
  	@retval        0 w przypadku bledu */
int readFile (std::string &fileName, int &fileSize, unsigned char *&dataPtr);

/** Zapisuje zakodowany plik. 
	Brakujace bity do bajtu wypeniane sa zerami. 
	Na koniec jeden dodatkowy bajt mowiacy o ilosci dopisanych zer.
	
	@param[in]     fileName nazwa pliku do zapisania
	@param[in]     encodeData dane do zapisania	
		
  	@retval        1 w przypadku poprawnego zapisu
  	@retval        0 w przypadku bledu  */
int writeEncodeFile(std::string &fileName, std::string &encodeData);

/** Zapisuje slownik do pliku tekstowego. 
	
	@param[in]     fileName nazwa pliku do zapisania
	@param[in]     fileContent dane do zapisania	
		
  	@retval        1 w przypadku poprawnego zapisu
  	@retval        0 w przypadku bledu  */
int writeDictionary (std::string &fileName, std::string *fileContent);

/** Wczytuje do pamiêci slownik z pliku tekstowego. 
	
	@param[in]     fileName nazwa pliku do wczytania
	@param[out]    dictionary wczytane dane	[symbol/sekwencja]
		
  	@retval        1 w przypadku poprawnego zapisu
  	@retval        0 w przypadku bledu  */
int loadDictionary(std::string &fileName, std::map<std::string, int> &dictionary);

/** Zapisuje odkodowany plik. 
		
	@param[in]     fileName nazwa pliku do zapisania
	@param[in]     fileSize rozmiar danych do zapisania
	@param[in]	   dataPtr dane do zapisania
		
  	@retval        1 w przypadku poprawnego zapisu
  	@retval        0 w przypadku bledu  */
int writeFile (std::string &fileName, int &fileSize, unsigned char *&dataPtr);