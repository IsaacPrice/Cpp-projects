#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<string>

using namespace std;

// This is to organize all of the information about a single employee
class employee {
public:
	// Constructor for the class
	employee(string Id = "undefined", string Name = "undefined", string Position = "undefined", double Salary = -1.0) : id(Id), name(Name), position(Position), salary(Salary) {};

	// This will change only the position of the employee
	string getPosition() { return position; };
	void updatePosition(string NewPosition) {
		if (NewPosition == position) { // Mentoning if they are trying to change it to the same position
			cout << name << " already has this position." << endl;
		}
		position = NewPosition;
	}

	// This will get the name and the id
	string getId() { return id; };
	string getName() { return name; };
	void setId(string ID) { id = ID; };
	void setName(string Name) { name = Name; };

	// Getters and Setters for the Employees salaries
	double getSalary() { return salary; };
	void setSalary(double NewSalary) { salary = NewSalary; };

private:
	string id; // The company cannot have two employees with the same ID
	string name;
	string position;
	double salary;
};

class company {
public:
	// Constructor for the comapny class (doesn't need anything fancy)
	company() {};

	// This will fill employees from the given csv file
	bool readCSV(string Filepath) {
		filepath = Filepath;
		ifstream file(filepath);
		if (!file.is_open()) { // Prompts the user if there is an error
			cout << "Error opening the file." << endl;
			return false;
		}
		
		string line, word;

		// This will go through the file, line by line
		while (getline(file, line)) {
			stringstream s(line);
			employee tempEmployee;

			getline(s, word, ','); // Gets the ID of the employee
			tempEmployee.setId(word);
			
			getline(s, word, ','); // Gets the Name of the employee
			tempEmployee.setName(word);

			getline(s, word, ','); // Gets the position of the employee
			tempEmployee.updatePosition(word);

			getline(s, word, ','); // Gets the salary of the employee
			tempEmployee.setSalary(stod(word));

			// Finally adds the employee with all of the others
			employees.insert(make_pair(tempEmployee.getId(), tempEmployee));
		}

		// Properly closes the file
		file.close();
		return true;
	}

	// This will add in a new employee
	bool addEmployee() {
		string userInput;
		employee tempEmployee;

		cout << "Enter the ID of the employee: ";
		cin >> userInput; 

		// This is to make sure that there is only one employee per ID
		while (employees.count(userInput)) {
			cout << "There is already an employee with that ID." << endl;
			cout << "Enter the ID of the employee: ";
			cin >> userInput;
		}
		tempEmployee.setId(userInput);

		// Gets the name of the employee
		cout << "Enter the name of the employee: ";
		cin >> userInput;
		tempEmployee.setName(userInput);

		// Gets the position of the employee
		cout << "Enter the position of the employee: ";
		cin >> userInput;
		tempEmployee.updatePosition(userInput);

		// Gets the salary of the employee
		cout << "Enter the salary of the employee: ";
		cin >> userInput;
		tempEmployee.setSalary(stod(userInput));

		// Adds the temporary employee to the rest
		employees.insert(make_pair(tempEmployee.getId(), tempEmployee));
		return true;
	}

	// This will remove an employee of the users choice
	bool removeEmployee(string ID) {
		if (!employees.count(ID)) { // Prompting the user if there isnt a 
			cout << "There is no employee with this ID." << endl;
			return false;
		}
		// Successfully removes the employee
		employees.erase(ID);
		return true;
	}

	// This will update the employees position
	bool updatePosition() {
		string userInput, ID;

		// Gets the ID of the employee
		cout << "Enter the ID of the employee: ";
		cin >> userInput;

		if (!employees.count(userInput)) { // Prompts the user if there isn't an employee
			cout << "There is no employee with that ID." << endl;
			return false;
		}
		ID = userInput;

		// Gets the new position and finilizes the changes
		cout << "Enter the new postition of the employee: ";
		cin >> userInput;
		employees[ID].updatePosition(userInput);
		return true;
	}

	// Updates Employees Salary
	bool updateSalary() {
		string Salary, ID;

		// Gets the Id of the employee
		cout << "Enter the employees ID: ";
		cin >> ID;

		if (!employees.count(ID)) { // Tells the user if there is an error
			cout << "There is no employee with that ID." << endl;
			return false;
		}

		// Gets the new salary and updates the employees pay
		cout << "Enter the new Salary: ";
		cin >> Salary;
		employees[ID].setSalary(stod(Salary));
		return true;
	}

	// Finds the employee based on their ID or name
	void findEmployee() {
		string userInput, searchFor;

		cout << "Do you want to search my name or id? ";
		cin >> userInput;

		if (userInput == "id") { // Searches using the map
			cout << "Enter the ID: ";
			cin >> searchFor;

			// Prints out the information about the employee
			cout << searchFor << " " << employees[searchFor].getName() << " " << employees[searchFor].getPosition() << " " << employees[searchFor].getSalary() << endl;
		}
		else if (userInput == "name") { // Searches by using a for loop
			cout << "Enter the name of the employee: ";
			cin >> searchFor;

			for (auto& currPair : employees) {
				if (currPair.second.getName() == searchFor) {
					// Prints out the info about the user
					cout << currPair.second.getId() << " " << searchFor << " " << currPair.second.getPosition() << " " << currPair.second.getSalary() << endl;
				}
			}
		}
	}

	// Displays all of the employees information
	void printEmployeesInfo() {
		cout << "ID Name Position Salary" << endl;
		for (auto& currPair : employees) {
			// Prints out the info about the employee
			cout << currPair.first << " " << currPair.second.getName() << " " << currPair.second.getPosition() << " " << currPair.second.getSalary() << endl;
		}
	}

	// Calculates total payroll
	void printTotalPayroll() {
		double total = 0;
		for (auto& currPair : employees) {
			total += currPair.second.getSalary();
		}
		cout << "Total Payroll: " << total << endl;
	}
private:
	map<string, employee> employees;
	string filepath;
};

int main() {
	company apple;
	string userInput;

	apple.readCSV("data.csv");

	// This will keep going until The user exits
	while (true) {
		cout << "1. Add New Employee\n2.Remove An Employee\n3.Update an Employee's Position\n4. Update an Employees Salary\n5. Search For an Employee\n6. Display All Employees\n7. Calculate Total Payroll" << endl;
		cout << "Choose an option (exit to exit): ";
		cin >> userInput;

		if (userInput == "exit") {
			break;
		}
		else if (userInput == "1") {
			apple.addEmployee();
		}
		else if (userInput == "2") {
			cout << "Enter Employees ID: ";
			cin >> userInput;
			apple.removeEmployee(userInput);
		}
		else if (userInput == "3") {
			apple.updatePosition();
		}
		else if (userInput == "4") {
			apple.updateSalary();
		}
		else if (userInput == "5") {
			apple.findEmployee();
		}
		else if (userInput == "6") {
			apple.printEmployeesInfo();
		}
		else if (userInput == "7") {
			apple.printTotalPayroll();
		}
	}

	return 0; // Means that the program ran as normal
}