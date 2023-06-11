#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<typeinfo>
using namespace std;

void readCsv(string fileName, vector<vector<int>> array) {
    ifstream File(fileName);
    string Line;
    string section = "";
    int column = 0;
    int row = -1;
    vector<int> temp;

    // File.open("numbers.csv");  Error handling
    if (!File) {
        cout << "error opening the file" << endl;
    }

    // This will read the file, line by line
    while (getline(File, Line)) {
        row++;

        // This loops through the Line, character by character
        while (column < Line.size()) {
            
            // Checks if there is a seperator
            if (Line[column] == ',') {
                temp.push_back(stoi(section));
                cout << section << " ";
                section = "";
            }
            else {
                section += Line[column];
            }

            column++;
        }   

        cout << endl;
        temp.push_back(stoi(section));
        array.push_back(temp);
        temp.clear();
    }
}

int main() {
    vector<vector<int>> values;

    readCsv("numbers.csv", values);

    return 0;
}