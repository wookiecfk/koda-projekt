#include <iostream>
#include <fstream>
using namespace std;

int readFile (std::string &fileName, int &fileSize, unsigned char *&dataPtr);

int main () {

	int fileSize =0;
	unsigned char *dataPtr;
	std::string  fileName = "figure_1.png";
    
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

int readFile (std::string &fileName, int &fileSize, unsigned char *&dataPtr) {
	//streampos size;
	int size;
		
	ifstream file (fileName, ios::in|ios::binary|ios::ate);
	if (file.is_open())
	{
		file.seekg (0, ios::end);
		size = (int)file.tellg();
		fileSize = size;
		cout <<"size: " << size <<endl;
		dataPtr = new unsigned char [size]();
		file.seekg (0, ios::beg);
		file.read ((char*)dataPtr, size);
		file.close();
		return 1;
	}
	else cout << "Unable to open file";
	return NULL;
}

