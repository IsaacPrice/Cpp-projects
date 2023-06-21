#ifndef CSVREADER_CLASS_H
#define CSVREADER_CLASS_H
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class csvReader {
public:
    csvReader();
    ~csvReader();

    // This will check if the user inputted a proper filepath
    bool setFilepath(string Filepath = "null") {
        // If the user didn't provide a filepath, it will prompt the user for one
        if (Filepath != "null") {
            cout << "No filepath entered, enter one here: " << endl;
            cin >> Filepath;
        }

        File.open(Filepath);
        if (!File.is_open()) {
            cout << "Error opening file" << endl;
            return false;
        }
        return true;
    }

private:
    ifstream File;
    vector<vector<string>> contents;
};

#endif