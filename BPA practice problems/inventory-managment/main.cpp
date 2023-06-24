#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<string>

using namespace std;

// This is to store the information effectively
class item {
public:
	// Constructor with all of the parameters that isn't required but allowed
	item(int Id = -1, string Name = "undefined", int Quantity = -1, double Price = -1.0) : id(Id), name(Name), quantity(Quantity), price(Price) {};

	// Getters ans Setters for the values
	int getId() { return id; };
	void setId(int Id) { id = Id; };

	string getName() { return name; };
	void setName(string Name) { name = Name; };

	int getQuantity() { return quantity; };
	void setQuantity(int Quantity) { quantity = Quantity; };

	double getPrice() { return price; };
	void setPrice(int Price) { price = Price; };

private:
	int id;
	string name;
	int quantity;
	double price;
};

// This is to organize all of the items well
class inventory {
public:
	// Constructor for the inventory class
	inventory(map<int, item> Items = {}) : items(Items) {};

	// This will fill out the inventory based on the information in the csv
	bool loadCSV(string Filepath) {
		filepath = Filepath; // We are saving this for when we make a change and want to save it again
		ifstream file(filepath);
		if (!file.is_open()) // Making sure that the file is opened
			cout << "Failed to open file" << endl;

		string line, word;

		// Reads the file, line by line
		while (getline(file, line)) {
			stringstream s(line);
			item tempItem;

			// Gets the ID for the given line
			getline(s, word, ',');
			tempItem.setId(stoi(word));

			// Gets the Name
			getline(s, word, ',');
			tempItem.setName(word);

			// Gets the Quantity
			getline(s, word, ',');
			tempItem.setQuantity(stoi(word));

			// Gets the Price
			getline(s, word, ',');
			tempItem.setPrice(stod(word));

			// Adds the given Item to the map
			items.insert(make_pair(tempItem.getId(), tempItem));
		}

		// Finish the operation correctly
		file.close();
		return true;
	}

	// This will save the file by re-writing it
	bool saveCSV() {
		ofstream file(filepath);
		if (!file.is_open()) // Giving an error if there is one
			cout << "Error opening file" << endl; return false;

		// Loops through all of the pairs and writes them to the file
		for (auto& currPair : items) {
			file << currPair.second.getId() << ',' << currPair.second.getName() << ',' << currPair.second.getQuantity() << ',' << currPair.second.getPrice() << endl;
		}

		return false;
	}

	// This adds stock to a certain item
	bool add(int id, int quantity) {
		if (!items.count(id))
			cout << "Failed to find item with that id." << endl;

		// Adds the quantity to the total quantity
		items[id].setQuantity(items[id].getQuantity() + quantity);
		return true;
	}

	// This adds items to the inventory
	void newItem(item toAdd) {
		items.insert(make_pair(toAdd.getId(), toAdd));
	}

	// Function to simulate a sale
	bool sale(int id, int quantity) {
		if (!items.count(id)) // Makes sure that there is an object there
			cout << "Failed to find object with id: " << id << endl;
		
		int quantityAvalible = items[id].getQuantity();

		if (quantityAvalible < quantity)// Makes sure that there is enough in stock
			cout << "Not enough stock to get what was requested.\n";
			return false;
		
		items[id].setQuantity(quantityAvalible - quantity);
		return true; // Means everything went well and the value was modified
	}

	// This will add all of the prices * quantities to get the total
	int totalInventoryValue() {
		int total = 0;
		for (auto& currPair : items) {
			total += currPair.second.getPrice() * currPair.second.getQuantity();
		}
		return total;
	}

	// This will print the information about each product
	void printInfo() {
		cout << "Item ID  Name   Quantity  Price(usd)\n";
		for (auto& currPair : items) {
			cout << currPair.first << " " << currPair.second.getName() << " " << currPair.second.getQuantity() << " " << currPair.second.getPrice() << endl;
		}
	}

private:
	map<int, item> items;
	string filepath;
};

int main() {
	inventory something;
	string userInput;
	int ID;

	// Loads the data from the file
	something.loadCSV("data.csv");

	// This will continue to get inputs intil the user types exit
	while (true) {
		cout << "1. Add stock\n2. Add new item\n3. Record sale\n4. See total inventory value\n5. Show info of all items" << endl;
		cin >> userInput;

		// Does the function the user wishes
		if (userInput == "exit") {
			break;
		}
		else if (stoi(userInput) == 1) {
			cout << "Enter the id of the item: "; 
			cin >> userInput; // Getting the items ID
			ID = stoi(userInput);

			cout << "Enter the amount to add: ";
			cin >> userInput; // Gets the quantity and adds it
			something.add(ID, stoi(userInput));
		}
		else if (stoi(userInput) == 2) {
			item tempItem;
			cout << "Enter the id of the item: ";
			cin >> userInput; // Gets the id for the object
			tempItem.setId(stoi(userInput));

			cout << "Enter the name of the item: ";
			cin >> userInput; // Gets the name of the item
			tempItem.setName(userInput);

			cout << "Enter the quantity of the item: "; // TODO: make this and price getter not accept negatives
			cin >> userInput; // Gets the quantity of the object
			tempItem.setQuantity(stoi(userInput));

			cout << "Enter the price of the item: ";
			cin >> userInput; // Gets the prive of the object
			tempItem.setPrice(stod(userInput));

			// Finnaly adds it to the class
			something.newItem(tempItem);
		}
		else if (stoi(userInput) == 3) {
			cout << "Enter the id of the item: ";
			cin >> userInput; // Getting the items ID
			ID = stoi(userInput);

			cout << "Enter the amount to remove: ";
			cin >> userInput; // Gets the quantity and adds it
			something.sale(ID, stoi(userInput));
		}
		else if (stoi(userInput) == 4) {
			cout << "Total inventory value: " << something.totalInventoryValue() << endl;
		}
		else if (stoi(userInput) == 5) {
			something.printInfo();
		}
	}
	something.saveCSV();
	return 0; // Means that the program ran sucessfully
}