#include "ItemTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Constructor: reads input. Generates frequency.dat backup file
ItemTracker::ItemTracker(const std::string& t_filename) {
	LoadDataFromFile(t_filename);
	CreateDataFile("frequency.dat");
}

// Reads raw data from input file and populates the map with item frequencies
void ItemTracker::LoadDataFromFile(const string& t_filename) {
	ifstream inFile(t_filename);
	if (!inFile.is_open()) {
		std::cerr << "Error opening file: " << t_filename << std::endl;
		return;
	}

	string item;
	while (inFile >> item) {
		m_itemFrequencies[item]++;
	}
	inFile.close();
}

// Data File Creation: Writes map contents to frequency.dat
void ItemTracker::CreateDataFile(const string& t_outputFileName) const {
	std::ofstream outFile(t_outputFileName);
	if (!outFile.is_open()) {
		std::cerr << "Error creating file: " << t_outputFileName << std::endl;
		return;
	}
	for (const auto& pair : m_itemFrequencies) {
		outFile << pair.first << " " << pair.second << endl;
	}
	outFile.close();
}

// Menu One: Returns numeric frequency for a specific word
int ItemTracker::GetItemFrequency(const string& t_item) const {
	auto it = m_itemFrequencies.find(t_item);
	if (it != m_itemFrequencies.end()) {
		return it->second;
	}
	return 0;
}

// Menu Two: Prints all items and their frequencies
void ItemTracker::PrintAllFrequencies() const {
	cout << "\n=====================================\n";
	cout << "        Item Frequencies:             \n";
	cout << "=====================================\n";
	for (const auto& pair : m_itemFrequencies) {
		cout << left << setw(15) << pair.first << "  " << pair.second << endl;
	}
	cout << "=====================================\n";
}

// Menu Three: Prints item frequencies as a histogram
void ItemTracker::PrintHistogram() const {
	cout << "\n=====================================\n";
	cout << "        Item Frequency Histogram:     \n";
	cout << "=====================================\n";
	for (const auto& pair : m_itemFrequencies) {
		cout << left << setw(15) << pair.first << "  ";
		for (int i = 0; i < pair.second; ++i) {
			cout << "*";
		}
		cout << endl;
	}
	cout << "=====================================\n";
}