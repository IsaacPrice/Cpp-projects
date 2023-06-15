// Solution
#include<iostream>
using namespace std;

int main() {
    int number1, number2, result; // Defining the variables for the addition

    // Prompts the user and gets the first number
    cout << "Enter the first number to add: ";
    cin >> number1;

    // Prompts the user and gets the second number
    cout << "Enter the second number to add: ";
    cin >> number2;

    // Adds the numbers together
    result = number1 + number2;

    cout << "Result: " << result << endl;

    return 0;
}