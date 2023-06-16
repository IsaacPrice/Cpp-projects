// Solution
#include<iostream>
using namespace std;

// This creates a global variable that is the value of PI
double PI = 3.14159265358979323846;

int main() {
    double radius; // Create the varibles to hold the radius given by the user, and the area and circumference
    double area, circumference;

    // Prompts the user for the radius, and assigns it to the radius variable
    cout << "Enter the radius of the circle: " << endl;
    cin >> radius;

    // Calculates the area and circumference
    double area = PI * radius * radius;
    double circumference = 2 * PI * radius;

    // Prints the results onto the screen
    cout << "Area: " << area << endl;
    cout << "Circumference: " << circumference << endl;

    return 0;
}