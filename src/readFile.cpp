#include <iostream>
#include <fstream>
using namespace std;

int readFile (std::string &fileName, int &fileSize, char *&dataPtr);

int main () {

	int fileSize =0;
	char *dataPtr;
	std::string  fileName = "lolCH1_file_0.bin";
    
	int status = readFile(fileName, fileSize, dataPtr);
	cout <<fileSize << endl;
	if (status)
		cout << " OK " <<endl;
	else
		cout << " Error " << endl;

	for (int i = 0; i< 10; i++)
		cout << (int)dataPtr[i] << " ";
	
	
	cin.get();
	cin.get();
	delete[] dataPtr;
}

int readFile (std::string &fileName, int &fileSize, char *&dataPtr) {
	//streampos size;
	int size;
		
	ifstream file (fileName, ios::in|ios::binary|ios::ate);
	if (file.is_open())
	{
		file.seekg (0, ios::end);
		size = (int)file.tellg();
		fileSize = size;
		cout <<"size: " << size <<endl;
		dataPtr = new char [size]();
		file.seekg (0, ios::beg);
		file.read (dataPtr, size);
		file.close();
		return 1;
	}
	else cout << "Unable to open file";
	return NULL;
}

