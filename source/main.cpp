#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	cout << "Hello World" << endl;

	ifstream myFile;
	myFile.open("resource/HelloWorldtest", ifstream::in);
	if (myFile.is_open()) {
		myFile.seekg(0, ios::end);
		int size = myFile.tellg();
		myFile.seekg(0, ios::beg);
		cout << "this file is " << size << " bytes long" << endl;
		char *sz  = new char[size+1];
		sz[size] = '\0';
		myFile.read(sz, size);
		cout << "Contents" << endl;
		myFile.close();
		cout << sz << endl;
	}
	return 0;
}