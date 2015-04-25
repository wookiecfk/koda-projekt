#include "fileIO.h"
using namespace std;

int readFile (std::string &fileName, int &fileSize, unsigned char *&dataPtr) 
{
	int size;
	ifstream file (fileName, ios::in|ios::binary|ios::ate);

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

