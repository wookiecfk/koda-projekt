#include "huffman.h"

extern int readFile (std::string &fileName, int &fileSize, unsigned char *&dataPtr);

int staticCoder(std::string fileName)
{
	int fileSize = 0;						//rozmiar pliku
	unsigned char *dataPtr;					//wskaznik do pliku
	int *prob = new int[dictionarySize]();	//wskaznik do tablicy z p-stwem
	node *tree;								//wskaünik do drzewa
	//int codedSymbols[dictionarySize];		//zakodowane symbole
	std::string codedSymbols[dictionarySize];
	for(int i = 0; i < dictionarySize; i++)
		codedSymbols[i].clear();

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

	buildTree(tree, prob);

	createCodes(codedSymbols, tree, "");

	for(int i = 0; i < dictionarySize; i++)
		std::cout<< i << " " << codedSymbols[i] << std::endl;

	delete[] dataPtr;
	delete[] prob;
	return 1;
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
	//std::cout <<"buildtree"<<std::endl;
	for(int i = 0; i < dictionarySize; i++)
	{
		nodes[i] = new node();
		nodes[i]->value = prob[i];
		nodes[i]->sign = i;
		nodes[i]->left = NULL;
		nodes[i]->right = NULL;
	}

	for(int i = 1; i < dictionarySize; i++)
	{
		sub1 = findSubtree(nodes, -1, i);
		sub2 = findSubtree(nodes, sub1, i);
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

int findSubtree(node *nodes[], int val, int sign)
{
	int res = -1;
	int index = 0;

	while(nodes[index]->value == -1 || index == val)
		index++;

	//std::cout <<"findsubtree"<<std::endl;
	for(int i = 1; i < dictionarySize; i++)
	{
		//if(i != sign)
		{   
			int tmpValue = nodes[i]->value;
			//std::cout <<"i: " << i << " tmpVal " << tmpValue << " nodes[sign]: " << nodes[sign]->value <<std::endl;
			//if(tmpValue < nodes[sign]->value && tmpValue > res && tmpValue != val && tmpValue != -1)
			if(nodes[i]->value < nodes[index]->value && i != val && nodes[i]->value != -1)
			{
				//res = nodes[i]->value;
				index = i;
			}
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
	return 1;
}
