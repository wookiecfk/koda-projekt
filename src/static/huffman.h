#include <string>
#include <iostream>
#include <map>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include "huffmanType.h"
#include "../fileIO.h"


/** Koder statyczny.
	
	@param[in]    fileName nazwa pliku do zakodowania
	
	@retval        1 w przypadku poprawnego kodowania
  	@retval        0 w przypadku bledu */
int staticCoder(std::string fileName);

/** Liczy czestosc wystepowania poszczegolnych elementow.
	
	@param[in]    fileSize rozmiar wczytanego pliku w bajtach
	@param[in]    dataPtr wskaznik do danych z pliku wczytanych do pamieci
	@param[out]   prob wskaznik do tablicy z czestoscia wystepowania poszczegolnych elementow */
void countProb(int &fileSize, unsigned char *dataPtr, int *prob);

/** Dla kazdego elementu tworzy drzewo. Kazde trzewo dostaje przypisany 'znak'
	oraz czestosc wystepowania. Galezie (lewa/prawa) zadeklarowane sa jako puste.
	
	Nastepnie wyszukiwane sa poddrzewa.
	Algorytm wyszukiwania poddrzewa:
	- znajdz piewsze drzewo ktore nie ma poddrzewa
	- sprawdz pozostale wolne drzewa i wybierz to, ktore ma mniejsza czestosc wystepowania
	- znajdz drugie poddrzewo dla danego drzewa z pominieciem drzewa z poprzedniego kroku
	(drugie poddrzewo ma wieksza czestosc wystepowania niz pierwsze)
	- miejsce pierwszego poddrzewa wstaw nowe drzewo
	- dla utworzonego drzewa ustaw -1 jako czestosc wystepowania - oznaczenie ze drzewo posiada juz poddrzewa
	- do lewej galezi przypisz drugie poddrzewo (z wieksza czestoscia wystepowania)
	- do prawej galezi przypisz pierwsze poddrzewo

	@param[out]   tree poczatek drzewa
	@param[in]    prob czestosci wystepowania*/
void buildTree(node *&tree, int *&prob);

/** Znajdz wolne drzewo (tzn. bez galezi). W wyszukiwaniu
	pomin drzewo o znaku val.

	@param[out]   nodes tablica drzew
	@param[in]    val czestosci wystepowania
	
	@retval        index (znak) znalezionego drzewa*/
int findSubtree(node *nodes[], int val);

/** Czyta sekwencje z drzewa dla danego znaku.
	Rekurencyjne przeszukuje cale drzewo. Jesli przeszukiwana jest lewa
	galaz do sekwencji dopisywane jest '0', jesli przeszykiwana jest prawa
	galaz do sekwencji dopisywane jest '1'.

	@param[out]   codedSymbold tablica z zakodowanymi sekwencjami
	@param[in]	  tree poczatek drzewa
	@param[in]    codedSeq aktualnie czytana sekwencja*/
void createCodes(std::string codedSymbols[], node *tree, std::string codedSeq);

/** Zakodowanie wczytanego pliku

	@param[in]    dataPtr dane do zakodowania
	@param[in]	  codedSymbols slownik
	@param[in]    fileSize rozmiar danych do zakodowania
	
	@retval       encodeData zakodowane dane w postaci jednej dlugiej sekwencji*/
std::string encode(unsigned char *dataPtr, std::string codedSymbols[], int fileSize);

/** Dekoder.
	
	@param[in]    fileName nazwa pliku do odkodowania
	
	@retval        1 w przypadku poprawnego odkodowania
  	@retval        0 w przypadku bledu */
int staticDecoder(std::string fileName);

/** Dekoder.
	
	@param[in]    dataPtr dane do odkodowania
	@param[in]    fileSize rozmiar danych do odkodowania
	@param[in]    dictionary slownik
	@param[in]    decoded dane zdekodowane
	
	@retval       dataSize rozmiar zdekodowanych danych*/
int decodingData(unsigned char *dataPtr, int fileSize, std::map<std::string, int> dictionary, unsigned char *decoded);