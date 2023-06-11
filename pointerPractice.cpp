#include<iostream>
#include<vector>
#include<memory>
using namespace std;

int main() {
    // Making a standard pointer
    vector<char>* firstName = new vector<char>{'I', 's', 'a', 'a', 'c'};

    for (unsigned int i = 0; i < firstName->size(); i++) {
        cout << firstName->at(i);
    }

    return 0;
}