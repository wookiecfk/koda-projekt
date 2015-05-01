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

int writeEncodeFile(std::string &fileName, std::string &encodeData)
{
	long int dataSize = encodeData.length();
	long int missed = 8 -(dataSize % 8);
	char extraChar = missed;
	//std::cout <<"missed: "<<missed << "\n";
	boost::dynamic_bitset<unsigned char> bitStream(encodeData);
	//std::cout <<"streamsize: "<<bitStream.size() << "\n";
	/*for(int i = 0; i < dataSize; i++)
		bitStream[i] = encodeData[i];*/
	/*for(int i = 0; i < 16; i++)
	std::cout << bitStream[i] << " " << encodeData[(dataSize-1)-i]<<"\n";*/
	char one = 1;
	char zero = 0;
	std::ofstream myFile (fileName.c_str(), ios::out | ios::binary);
	if (myFile.is_open())
	{
		long int tmp = dataSize+missed;
		int i = 0;
		while(i < tmp)
		{
			char sign = 0;
			for(int j = i; j < i+8; j++)
				if(bitStream[j] == 1)
					sign = sign << 1 | one;
				else
					sign = sign << 1 | zero;
			//std::cout << (int)sign<<std::endl;
    		myFile << sign;
			i += 8;
		}
		myFile << extraChar;
		myFile.close();
		
		return 1;
	}
	else 
		return 0;		
}

int writeDictionary (std::string &fileName, std::string *fileContent)
{
	const char * fileNameChar = fileName.c_str();
	ofstream myFile(fileNameChar);
	
	if (myFile.is_open())
  	{
		for(int i=0; i<dictionarySize; i++){
			myFile << i << " " << fileContent[i].c_str() << std::endl;
		}
    		myFile.close();

		return 1;
	}
	else
		return 0;
} 

int loadDictionary(std::string &fileName, std::map<std::string, int> &dictionary)
{
	std::ifstream infile(fileName.c_str());
	
	if(infile.is_open())
	{
		for(int i = 0; i < dictionarySize; i++)
		{
			int value; 
			infile >> value;
			std::string key;
			infile >> key;
			dictionary[key] = value;
		}
		infile.close();
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