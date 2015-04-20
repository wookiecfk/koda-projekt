#include <iostream>
#include <fstream>
using namespace std;

char * readFile (char* fileName);

int main () {
	char * memblock = readFile((char*)"example.bin");
	cout<<memblock;
	delete[] memblock;
}

char * readFile (char* fileName) {
	streampos size;
	char * memblock;
	
	ifstream file (fileName, ios::in|ios::binary|ios::ate);
	if (file.is_open())
	{
		size = file.tellg();
		memblock = new char [size];
		file.seekg (0, ios::beg);
		file.read (memblock, size);
		file.close();
		return memblock;
	}
	else cout << "Unable to open file";
	return NULL;
}
