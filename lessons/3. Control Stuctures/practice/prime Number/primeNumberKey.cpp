// Solution
#include<iostream>
using namespace std;

int main() {
    int userNumber;

    // This will keep repeating forever
    while (true) {
        // Gets the users number
        cout << "Enter the number to check (-1 to exit): ";
        cin >> userNumber;

        // Checks if the user wanted to exit
        if (userNumber == -1) {
            break;
        }

        // The numbers is prime, until proven not prime from the loop below
        bool isPrime = true;

        // The number has to start at 2, since 0 will give an error, and 1 doesn't mean that it's prime
        // Also, when the i*i used, it is to make sure that it isn't repeating the same numbers
        for (unsigned int i = 2; i * i < userNumber; i++) { 
            if (userNumber % i == 0) { // When it devides evenly, it means that its not a prime
                isPrime = false;
                break;
            }
        }

        // Makes sure that the number is positive and isn't 1
        if (isPrime && userNumber > 1) {
            cout << "The number is prime." << endl;
        } else {
            cout << "The number is not prime." << endl;
        }
    }

    return 0;
}
