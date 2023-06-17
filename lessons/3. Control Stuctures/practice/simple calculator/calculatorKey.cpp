// Solution
#include<iostream>
using namespace std;

int main() {
    double number1, number2; // This is to hold the numbers from the user
    char operation; // This will hold the +, -, /, *

    // This will make the program run forever
    while (true) {
        // This will get the two numbers from the user
        cout << "Enter two numbers: " << endl;
        cin >> number1 >> number2;

        // This will get the operator from the user
        cout << "Enter a +, -, *, or / (e to exit): ";
        cin >> operation;

        // Checks if the user wanted to exit
        if (operation == 'e') {
            break;
        }

        // This performs the calculation based on the operator
        double result;
        switch (operation) {
            case ('+'):
                result = number1 + number2;
                break;
            case ('-'):
                result = number1 - number2;
                break;
            case ('*'):
                result = number1 * number2;
                break;
            case ('/'):
                result = number1 / number2;
                break;
            default:
                cout << "Entered an invalid operator" << endl;
                break;
        }

        cout << "Result: " << result << endl;
    }

    return 0;
}
