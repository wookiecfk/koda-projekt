#include "fileIO.h"
using namespace std;

int readFile (std::string &fileName, int &fileSize, unsigned char *&dataPtr) 
{
	int size;
	//std::string --> const char * conversion required by my compiler
	const char * fileNameChar = fileName.c_str();

	ifstream file (fileNameChar, ios::in|ios::binary|ios::ate);

	if (file.is_open())
	{
		file.seekg (0, ios::end);
		size = (int)file.tellg();
		fileSize = size;
		dataPtr = new unsigned char [size]();
		file.seekg (0, ios::beg);
		file.read ((char*)dataPtr, size);
		file.close();
		return 1;
	}
	else 
		return 0;
}

int writeFile (std::string &fileName, int &fileSize, unsigned char *&dataPtr)
{
	const char * fileNameChar = fileName.c_str();

	ofstream myFile (fileNameChar, ios::out | ios::binary);
	if (myFile.is_open()){
    		myFile.write ((char*)dataPtr, fileSize);
		return 1;
	}
	else 
		return 0;		
}

int writeDictionary (std::string &fileName, std::string *fileContent)
{
	const char * fileNameChar = fileName.c_str();
	ofstream myFile (fileNameChar);
	if (myFile.is_open())
  	{
		for(int i=1; i<=dictionarySize; i++){
			myFile<<i<<" "<<fileContent[i-1]<<std::endl;
		}
    		myFile.close();

		return 1;
	}
	else
		return 0;
} 

