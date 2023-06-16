// Solution
#include<iostream>
using namespace std;

int main() {
    double length, width; // Define the variables for the user's rectangles width and height
    double perimeter, area; // The solution for the given length and width

    // Prompts the user for the rectangle length
    cout << "Enter the length of the rectangle: ";
    cin >> length;

    // Gets the rectangle width
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    // Performs the calculations for the rectangle
    perimeter = (length * 2) + (width * 2);
    area = length * width;

    // Prints the results to the screen
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;

    return 0;
}