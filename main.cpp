#include <iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
	ifstream File;
	string Line;

	File.open("super.csv");

	while (getline(File, Line)) {
		cout << Line << endl;
	}

	return 0;
}