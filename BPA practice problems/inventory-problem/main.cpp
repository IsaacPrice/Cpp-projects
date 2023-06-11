#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

#pragma region item class

class item {
public:
    // All of the constructor functions
    item();
    item(int id);
    item(int id, string Name);
    item(int id, string Name, double Price);
    item(int id, string Name, double Price, int Quantity);

    // All of the get functions
    int getID();
    string getName();
    double getPrice();
    int getQuantity();

    // All of the set functions
    void setID(int id);
    void setName(string Name);
    void setPrice(double Price);
    void setQuantity(int Quantity);

    private:

    int ID;
    string name;
    double price;
    int quantity;
};

// This is the constructor for when there is no given parameters
item::item() {
    ID = 0;
    name = "";
    price = 0;
    quantity = 0;
}

// This is for when they give the ID
item::item(int id) {
    ID = id;
    name = "";
    price = 0;
    quantity = 0;
}

// This is for when they give the name and the ID
item::item(int id, string Name) {
    ID = id;
    name = Name;
    price = 0;
    quantity = 0;
}

// This is for when they give the name, id, and the price
item::item(int id, string Name, double Price) {
    ID = id;
    name = Name;
    price = Price;
    quantity = 0;
}

// This is for when they give all of the variables
item::item(int id, string Name, double Price, int Quantity) {
    ID = id;
    name = Name;
    price = Price;
    quantity = Quantity;
}

// This returns the id of the object
int item::getID() {
    return ID;
}

// This returns the name of the object
string item::getName() {
    return name;
}

// This returns the price of the object
double item::getPrice() {
    return price;
}

// This returns the quantity of the object
int item::getQuantity() {
    return quantity;
}

// This sets the ID of the object
void item::setID(int id) {
    ID = id;
}

// This sets the name of the object
void item::setName(string Name) {
    name = Name;
}

// This sets the price of the object
void item::setPrice(double Price) {
    price = Price;
}

// This sets the quantity of the object
void item::setQuantity(int Quantity) {
    quantity = Quantity;
}

#pragma endregion

// This will read the csv file and return the filled vector
vector<item> readCsv(string FilePath) {
    vector<item> items;
    ifstream File(FilePath);
    string Line, cacheWord;
    item cacheItem;
    int column;

    cacheWord = "";
    // This goes through the file, line by line
    while (getline(File, Line)) {
        cout << "Got into the mainframe" << endl;
        column = 0;
        // Gets the ID
        while (Line[column] != ',') {
            cacheWord += Line[column];
            column++;
        }
        cout << cacheWord << endl;
        cacheItem.setID(stoi(cacheWord));
        cacheWord = "";
        column++;

        // Gets the name
        while (Line[column] != ',') {
            cacheWord += Line[column];
            column++;
        }
        cout << cacheWord << endl;
        cacheItem.setName(cacheWord);
        cacheWord = "";
        column++;

        // Gets the price
        while (Line[column] != ',') {
            cacheWord += Line[column];
            column++;
        }
        cout << cacheWord << endl;
        cacheItem.setPrice(stod(cacheWord));
        cacheWord = "";
        column++;

        // Gets the quantity
        while (column < Line.size()) {
            cacheWord += Line[column];
            column++;
        }
        cout << cacheWord << endl;
        cacheItem.setPrice(stoi(cacheWord));
        cacheWord = "";
        column++;

        // Finally adds the item to the vector
        items.push_back(cacheItem);
    }

    return items;
}

int main() {
    vector<item> inventory = readCsv("storage.csv");
    ifstream file("storage.csv");
    string line;

    while (getline(file, line)) {
        cout << line << endl;
    }
    

    // This prints out all the items in the csv file
    for (auto& thingie : inventory) {
        cout << "got into the mainframe" << endl;
        cout << thingie.getID() << ", " << thingie.getName() << ", " << thingie.getPrice() << ", " << thingie.getQuantity() << endl;
    }

    return 0;
}