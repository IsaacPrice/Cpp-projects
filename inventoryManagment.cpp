#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<map>

using namespace std;

// The Inventory for each item is as such: product_id, product_name, category, quantity, unit_price
struct InventoryItem {
    string product_id;
    string product_name;
    string category;
    int quantity;
    double unit_price;
};

// The Order for each item is as such: product_id, quantity
struct OrderItem {
    string product_id;
    int quantity;
};

int main() {
    // Open the file
    ifstream inventoryFile("inventory.csv");

    // Check if the file is open
    if (!inventoryFile.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    // Create a vector of InventoryItems
    vector<InventoryItem> inventory;

    // Create a string to hold each line
    string line;
    
    // Read each line of the file
    while (getline(inventoryFile, line)) {
        // Create a string stream to read each line
        stringstream ss(line);

        // Create a vector of strings to hold each value
        vector<string> values;

        // Create a string to hold each value
        string value;

        // Read each value of the line
        while (getline(ss, value, ',')) {
            // Add the value to the vector
            values.push_back(value);
        }

        // Create an InventoryItem
        InventoryItem item;

        // Set the values of the InventoryItem
        item.product_id = values[0];
        item.product_name = values[1];
        item.category = values[2];
        item.quantity = stoi(values[3]);
        item.unit_price = stod(values[4]);

        // Add the InventoryItem to the vector
        inventory.push_back(item);
    }

    // Close the file
    inventoryFile.close();

    // Open the file containing the orders
    ifstream orderFile("sales.csv");

    // Check if the file is open
    if (!orderFile.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    // Create a vector of OrderItems
    vector<OrderItem> orders;

    // Read each line of the file
    while (getline(orderFile, line)) {
        // Create a string stream to read each line
        stringstream ss(line);

        // Create a vector of strings to hold each value
        vector<string> values;

        // Create a string to hold each value
        string value;

        // Read each value of the line
        while (getline(ss, value, ',')) {
            // Add the value to the vector
            values.push_back(value);
        }

        // Create an OrderItem
        OrderItem item;

        // Set the values of the OrderItem
        item.product_id = values[0];
        item.quantity = stoi(values[1]);

        // Add the OrderItem to the vector
        orders.push_back(item);
    }

    // Close the file
    orderFile.close();

    // Update the inventory
    for (int i = 0; i < orders.size(); i++) {
        // Get the order
        OrderItem order = orders[i];

        // Get the product id
        string product_id = order.product_id;

        // Get the quantity
        int quantity = order.quantity;

        // Find the item in the inventory
        for (int j = 0; j < inventory.size(); j++) {
            // Get the item
            InventoryItem item = inventory[j];

            // Check if the product ids match
            if (item.product_id == product_id) {
                // Update the quantity
                item.quantity -= quantity;

                // Update the inventory
                inventory[j] = item;

                // Break out of the loop
                break;
            }
        }
    }

    // Display the product sold, the total quantity sold, the total sales amount, and the remaining inventory for each product
    for (int i = 0; i < inventory.size(); i++) {
        // Get the item
        InventoryItem item = inventory[i];

        // Display the product sold
        cout << "Product sold: " << item.product_name << endl;

        // Display the total quantity sold
        cout << "Total quantity sold: " << item.quantity << endl;

        // Display the total sales amount
        cout << "Total sales amount: " << item.quantity * item.unit_price << endl;

        // Display the remaining inventory for each product
        cout << "Remaining inventory: " << item.quantity << endl;

        // Display a new line
        cout << endl;
    }

    return 0;
}