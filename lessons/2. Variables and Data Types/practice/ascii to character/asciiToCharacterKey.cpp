// Solution
#include<iostream>
using namespace std;

int main() {
    int userNumber; // Declare the variable to hold the users number

    cout << "Enter a number to convert to ascii: "; // Leaving out the endl leaves the cursor after the colon
    cin >> userNumber; // Gets the number the user wants

    cout << "Alphabetic character: " << char(userNumber) << endl;

    return 0;
}