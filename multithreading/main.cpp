#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<thread>
using namespace std;

void printSomething() {
    for (unsigned int i = 1; i <= 1000; i++) {
        cout << i << endl;
    }
}

int main() {
    thread t(printSomething);


    t.join();

    return 0;
}