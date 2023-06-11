#include<iostream>
#include<vector>
#include<string>
#include<memory> // Needed for the smart pointers
using namespace std;

template<typename T1, typename T2>
double add(T1 number1, T2 number2) {
    return number1 + number2;
}

int main() {
    int num1 = 89;
    float num2 = .9329f;

    cout << add(num1, num2) << endl;

    return 0;
}