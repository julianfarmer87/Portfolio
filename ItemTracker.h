#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <string>
#include <map>

class ItemTracker {
private:
	std::map<std::string, int> m_itemFrequencies;

	// Helper to process input file
	void LoadDataFromFile(const std::string& t_filename);

public:
	// Constructor initializes data and auto creates files
	ItemTracker(const std::string& t_filename);

	// Backup output file generation
	void CreateDataFile(const std::string& t_outputFileName) const;

	// Menu function
	int GetItemFrequency(const std::string& t_item) const;
	void PrintAllFrequencies() const;
	void PrintHistogram() const;

};

#endif // ITEM_TRACKER_H
