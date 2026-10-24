#include <iostream>
#include <string>
#include <limits>
#include "ItemTracker.h"

using namespace std;

void DisplayMenu() {
	cout << "\n********* Corner Grocer Menu *********\n";
	cout << "1. Search for an item frequency\n";
	cout << "2. Print all item frequencies\n";
	cout << "3. Print histogram of item frequencies\n";
	cout << "4. Exit\n";
	cout << "Enter your choice (1-4): ";
}

int main() {
	// Instantiate tracker and auto-generate frequency.dat
	ItemTracker tracker("CS210_Project_Three_Input_File.txt");

	int userChoice = 0;

	while (userChoice != 4) {
		DisplayMenu();

		// Input validation for menu choice
		if (!(cin >> userChoice)) {
			cout << "Invalid input. Please enter a number between 1 and 4.\n";
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
			continue;
		}

		switch (userChoice) {
		case 1: {
			string searchItem;
			cout << "Enter the item to search for: ";
			cin >> searchItem;
			int count = tracker.GetItemFrequency(searchItem);
			cout << searchItem << " was purchased " << count << " time(s).\n";
			break;
		}
		case 2:
			tracker.PrintAllFrequencies();
			break;
		case 3:
			tracker.PrintHistogram();
			break;
		case 4:
			cout << "Exiting the program.\n";
			break;
		default:
			cout << "Invalid choice. Please enter a number between 1 and 4.\n";
		}
	}

	return 0;
}