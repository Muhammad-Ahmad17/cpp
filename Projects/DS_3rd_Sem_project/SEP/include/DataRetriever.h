
#ifndef SEP_DATARETRIEVER_H
#define SEP_DATARETRIEVER_H

#include <string>
#include <vector>
#include <fstream>
#include "Date.h"

// Structure to represent a weather record
struct WeatherRecord {
    std::Date date;
    double temperature;
    double humidity;
};

class DataRetriever {
protected:
    std::vector<WeatherRecord> records;  // Vector to store records
public:
    bool loadData(const std::string &fileName); // Loads data from a file
    void addRecord(const std::Date &date, double temperature, double humidity);  // Adds a record
    void saveToFile(const std::string &fileName) const;  // Saves records to a file
    const std::vector<WeatherRecord>& getRecords() const;  // Gets the weather records
    void showAllRecords() const;

};

#endif // SEP_DATARETRIEVER_H
