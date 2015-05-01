#include "huffman.h"

int staticCoder(std::string fileName)
{
	int fileSize = 0;						//rozmiar pliku
	unsigned char *dataPtr;					//wskaznik do danych z pliku
	int *prob = new int[dictionarySize]();	//wskaznik do tablicy z p-stwem
	node *tree;								//wskaünik do drzewa
	std::string codedSymbols[dictionarySize];//zakodowane symbole

	//Czyszczenie tablicy z sekwencjami
	for(int i = 0; i < dictionarySize; i++)
		codedSymbols[i].clear();

	//Czytanie pliku
	if(!readFile(fileName, fileSize, dataPtr))
	{
		std::cout << "Nie mozna wczytac pliku!" <<std::endl;
		return 0;
	}
	
	//test for writeFile - IT WORKS 
	/*std::string fileNameOutput = "testedWrittenFile";
	writeFile(fileNameOutput, fileSize, dataPtr);*/
	
	//Liczenie prawdopodobienstwa
	countProb(fileSize, dataPtr, prob);

	//Budowanie drzewa
	buildTree(tree, prob);

	//Odczytywanie sekwencji z drzewa
	createCodes(codedSymbols, tree, "");
	
	//Wyswietlanie sekwencji
	/*for(int i = 0; i < dictionarySize; i++)
		std::cout<< i << " " << codedSymbols[i] << std::endl;*/

	//Zapis slownika do pliku tekstowego
	std::string dictionaryOutputName = fileName;
	dictionaryOutputName.append(".txt");
	writeDictionary(dictionaryOutputName, codedSymbols);

	//Zakodowanie wczytanego pliku
	std::string encodeData = encode(dataPtr, codedSymbols, fileSize);

	//Zapis zakodowanych danych do pliku
	{
		std::string tmp = fileName + ".stat";
		if(writeEncodeFile(tmp, encodeData))
			std::cout << "Zakodowany plik zapisano do: " << tmp << "\n";
	}

	delete[] dataPtr;
	delete[] prob;
	return 1;
}

std::string encode(unsigned char *dataPtr, std::string codedSymbols[], int fileSize)
{
	std::string encodeData;
	encodeData.clear();

	for(int i = 0; i < fileSize; i++)
		encodeData += codedSymbols[dataPtr[i]];

	return encodeData;
}

void createCodes(std::string codedSymbols[], node *tree, std::string codedSeq)
{
	//std::cout <<"createcodes"<<std::endl;
	if(tree->sign != -1)
		codedSymbols[(int)tree->sign] = codedSeq;
	else
	{
		createCodes(codedSymbols, tree->left, codedSeq + '0');
		createCodes(codedSymbols, tree->right, codedSeq + '1');
	}
	return;
}

void buildTree(node *&tree, int *&prob)
{
	node *tmp;
	node *nodes[dictionarySize];
	int sub1, sub2;
	
	for(int i = 0; i < dictionarySize; i++)
	{
		nodes[i] = new node();
		nodes[i]->value = prob[i];
		nodes[i]->sign = i;
		nodes[i]->left = NULL;
		nodes[i]->right = NULL;
	}

	for(int i = dictionarySize-1; i > 0; i--)
	{
		sub1 = findSubtree(nodes, -1);
		sub2 = findSubtree(nodes, sub1);
		tmp = nodes[sub1];
		nodes[sub1] = new node();
		nodes[sub1]->value = tmp->value + nodes[sub2]->value;
		nodes[sub1]->sign = -1;
		nodes[sub1]->left = nodes[sub2];
		nodes[sub1]->right = tmp;
		nodes[sub2]->value = -1;
	}
	tree = nodes[sub1];
}

int findSubtree(node *nodes[], int val)
{
	int index = 0;

	while(nodes[index]->value == -1 || index == val)
		index++;

	for(int i = 1; i < dictionarySize; i++)
	{
		if(nodes[i]->value < nodes[index]->value && i != val && nodes[i]->value != -1)
		{
			index = i;
		}
	}
	return index;
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
	unsigned char *dataPtr;					//wskaznik do danych z pliku
	int fileSize = 0;
	std::string dictionaryName = fileName.substr(0, fileName.length() - 5) + ".txt";
	std::map<std::string, int> dictionary;

	unsigned char *decoded = new unsigned char[1024*1024*100]();

	//Czytanie pliku
	if(!readFile(fileName, fileSize, dataPtr))
	{
		std::cout << "Nie mozna wczytac pliku!" <<std::endl;
		return 0;
	}
	
	if(!loadDictionary(dictionaryName, dictionary))
	{
		std::cout << "Brak slownika!" <<std::endl;
		return 0;
	}
	
	int decodedSize = decodingData(dataPtr, fileSize, dictionary, decoded);
	
	{
		std::string tmpName = fileName.substr(0, fileName.length() - 5);
		size_t pos = tmpName.find_last_of('.',tmpName.length());
		std::string lol = fileName + tmpName.substr(pos, std::string::npos);
		if(writeFile(lol, decodedSize, decoded))
			std::cout << "Zakodowany plik zapisano do: " << lol << "\n";
	}

	delete[] decoded;
	delete[] dataPtr;
	return 1;
}

int decodingData(unsigned char *dataPtr, int fileSize, std::map<std::string, int> dictionary, unsigned char *decoded)
{
	std::string seq;
	seq.clear();
	
	std::stringstream ss;
	std::string strSS;
	for(int i = 0; i < fileSize; i++)
	{
		int lol = dataPtr[i];
		char tmp[32];
		_itoa_s(lol,tmp,32,2);
		strSS = tmp;
		
		for(int i = 0; i < 8-strSS.length();i++)
			seq+='0';
		seq+=tmp;
	}
	boost::dynamic_bitset<unsigned char> dataBitset(seq);
	
	int decodedSize = 0; //rozmiar zdekodowanego pliku
	
	std::string sign;
	sign.clear();
	char extraSign = 0;
	char one = 1;
	char zero = 0;
	for(int i = 7; i>=0; i--)
		if(dataBitset[i] == 1)
					extraSign = extraSign << 1 | one;
				else
					extraSign = extraSign << 1 | zero;
	
	//for(int i = 0; i < 16; i++)
	std::cout << "dekoduje...\n";

	//for(int i = dataBitset.size()-1; i >= 8+extraSign; i--)
	for(int i = 8+(int)extraSign; i < dataBitset.size(); i++)
	{
		if(dataBitset[i] == 1)
					sign += '1';
				else
					sign += '0';
		auto search = dictionary.find(sign);
		if(search != dictionary.end())
		{
			decoded[decodedSize] = search->second;
			decodedSize++;
			sign.clear();
		}
	}	
	
	return decodedSize;
}