#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<unsigned int> numbers;
    for (unsigned int userNumber = 12; userNumber < 100000000; userNumber++) { 
    
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
            numbers.push_back(userNumber);
        } else {

        }
    }

    cout << numbers.size() << endl;

    return 0;
}
