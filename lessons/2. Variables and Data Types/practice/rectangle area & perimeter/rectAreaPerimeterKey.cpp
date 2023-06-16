// Solution
#include<iostream>
using namespace std;

int main() {
    double height, width; // Define the variables for the user's rectangles width and 
    double perimeter, area; // The solution for the given height and width

    // Prompts the user for the rectangle height
    cout << "Enter the height of the rectangle: ";
    cin >> height;

    // Gets the rectangle width
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    // Performs the calculations for the rectangle
    perimeter =  2 * (width + height);
    area = height * width;

    // Prints the results to the screen
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;

    return 0;
}