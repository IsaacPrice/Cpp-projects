// Solution
#include<iostream>
using namespace std;

int main() {
    int number1, number2, sum; // Defining the variables for the addition

    // Prompts the user and gets the first number
    cout << "Enter the first number to add: ";
    cin >> number1;

    // Prompts the user and gets the second number
    cout << "Enter the second number to add: ";
    cin >> number2;

    // Adds the numbers together
    sum = number1 + number2;

    cout << "Sum: " << sum << endl;

    return 0;
}