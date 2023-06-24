#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<map>

using namespace std;

// Class to hold all of the information about the items
class item {
public:
	// Constructor for the item object
	item(string ItemId = "undefined", double Price = -1.0, int Stock = -1) : itemId(ItemId), price(Price), stock(Stock) {};

	// Gets and Sets for the Item ID
	string* getItemId() { return &itemId; };
	void setItemId(string ItemId) { itemId = ItemId; };

	// Gets and sets for the price
	double* getPrice() { return &price; };
	void setPrice(double Price) { price = Price; };

	// Gets and sets for the stock
	int* getStock() { return &stock; };
	void setStock(int Stock) { stock = Stock; };


private:
	string itemId;
	double price;
	int stock;
};

// Class to store all of the items in a map
class store {
public:
	// Constructor for the Store object
	store(map<string, item> Items) : items(Items) {};

	// Gets and sets for the items
	map<string, item>* getItems() { return &items; };
	void setItems(map<string, item> Items) { items = Items; };

private:
	map<string, item> items;
};

// This is a class to store
class order {
public:
	// Consructor for the Order Object
	order(string OrderId = "undefined", map<string, int> AmountOrdered = {}, double TotalCost = -1.0) : orderId(OrderId), amountOrdered(AmountOrdered), totalCost(TotalCost) {};

	// Gets and sets for the order Id
	string* getOrderId() { return &orderId; };
	void setOrderId(string OrderId) { orderId = OrderId; };

	// Gets ans sets for the amount ordered
	map<string, int>* getAmountOrdered() { return &amountOrdered; };
	void setAmountOrdered(map<string, int> AmountOrdered) { amountOrdered = AmountOrdered; };

	// Gets and sets for the total cost
	double* getTotalCost() { return &totalCost; };
	void setTotalCost(double TotalCost) { totalCost = TotalCost; };

private:
	string orderId;
	map<string, int> amountOrdered;
	double totalCost;
};

int main() {

	return 0; // Ran succesfully
}