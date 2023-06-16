#include<iostream>
using namespace std;

int main() {
    int userNumber;

    cout << "Enter a positive number: ";
    cin >> userNumber;

    if (userNumber < 0) {
        cout << "Entered a negative number." << endl;
    }

    return 0;
}