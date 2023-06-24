#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>

#include<string>

using namespace std;

class company {
public:
	company(string CompanyID = "undefined", int AvalibleShares = -1, double SharePrice = -1.0) : companyID(CompanyID), avalibeShares(AvalibleShares), sharePrice(SharePrice) {};

	// Gets and Sets for the companyID
	string getCompanyID() { return companyID; };
	void setCompanyID(string CompanyID) { companyID = CompanyID; };

	// Gets and Sets for the avalible shares
	int getAvalibleShares() { return avalibeShares; };
	void setAvalibleShares(int AvalibleShares) { avalibeShares = AvalibleShares; };

	// Gets and Sets for the share price
	double getSharePrice() { return sharePrice; };
	void setSharePrice(double SharePrice) { sharePrice = SharePrice; };

private:
	string companyID;
	int avalibeShares;
	double sharePrice;

};

class StockMarket {
public:
	StockMarket() {};

	// Add and Delete companies
	void addCompany(company Company) { companies.insert(make_pair(Company.getCompanyID(), Company)); };
	void removeCompany(string companyID) { 
		if (!companies.count(companyID))
			throw runtime_error("Error finding object");
		companies.erase(companyID);
	};

	// This will give a -1 if there is an error, otherwise will get delete the amount of shares and give the price
	double buyShares(string CompanyID, int numberOfShares) {
		if (!companies.count(CompanyID) || numberOfShares > companies[CompanyID].getAvalibleShares())
			return -1;
		companies[CompanyID].setAvalibleShares(companies[CompanyID].getAvalibleShares() - numberOfShares);
		return companies[CompanyID].getSharePrice() * numberOfShares;
	}

	// This will give a -1 if there is an error, otherwise will add shares back 
	void sellShares(string CompanyID, int numberOfShares, double pricePerShare) {
		if (!companies.count(CompanyID)) // In the case that there isn't a company, it'l make a company
			companies.insert(make_pair(CompanyID, company(CompanyID, numberOfShares, pricePerShare)));
		companies[CompanyID].setAvalibleShares(companies[CompanyID].getAvalibleShares() + numberOfShares);
	}

	// This will check each company for the most shares avalible and return the ID
	string getCompanyWithMaxShares() {
		int tempMax = 0;
		for (auto& currPair : companies) {
			tempMax = (tempMax < currPair.second.getAvalibleShares()) ? currPair.second.getAvalibleShares() : tempMax;
		}
	}

	// This will check each company with the cheapest shares and returns the ID
	string getCompanyWithMinSharePrice() {
		double tempMax = 9999999999;
		for (auto& currPair : companies) {
			tempMax = (tempMax > currPair.second.getSharePrice()) ? currPair.second.getSharePrice() : tempMax;
		}
	}

	// This will read from the CSV and fill out the companies
	bool readCSV(string filePath) {
		ifstream file(filePath);
		if (!file.is_open()) // Returns false if it failed to open
			return false;

		companies.clear(); // Dont want to appened, but to replace with the content
		string line, word;
		while (getline(file, line)) {
			company tempCompany;
			stringstream s(line);

			// Gets the company ID, Avalible shares, and price from the csv
			getline(s, word, ',');
			tempCompany.setCompanyID(word);

			getline(s, word, ',');
			tempCompany.setAvalibleShares(stoi(word));

			getline(s, word, ',');
			tempCompany.setSharePrice(stod(word));

			// Adds the company to the map
			companies.insert(make_pair(tempCompany.getCompanyID(), tempCompany));
		}
	}

private:
	map<string, company> companies;
};

int main() {
	StockMarket bad;

	bad.readCSV("stocks.csv");

	

	return 0; // Program ran successfully
}