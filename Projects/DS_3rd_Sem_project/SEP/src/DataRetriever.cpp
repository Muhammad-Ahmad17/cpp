#include "DataRetriever.h"
#include <sstream>
#include <iostream>

using namespace std;

bool DataRetriever::loadData(const string &fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        return false;  // File opening failed
    }

    records.clear();  // Clear existing records
    string line;
    getline(file, line);  // Skip header line

    while (getline(file, line)) {
        istringstream stream(line);
        string dateStr;
        double temperature, humidity;

        if (getline(stream, dateStr, ',') &&
            stream >> temperature &&
            stream.ignore(1) &&
            stream >> humidity) {
            records.push_back({std::Date(dateStr), temperature, humidity});
        }
    }

    file.close();
    return true;  // File loaded successfully
}

void DataRetriever::addRecord(const Date &date, double temperature, double humidity) {
    records.push_back({date, temperature, humidity});
}

void DataRetriever::saveToFile(const string &fileName) const {
    ofstream file(fileName);
    if (file.is_open()) {
        file << "Date,Temperature,Humidity\n";
        for (const auto &record : records) {
            file << record.date.toString() << ',' << record.temperature << ',' << record.humidity << '\n';
        }
        file.close();
    }
}

const vector<WeatherRecord>& DataRetriever::getRecords() const {
    return records;
}

void DataRetriever::showAllRecords() const {
    if (records.empty()) {
        cout << "No records available." << endl;
        return;
    }

    // Table Header
    cout << "+------------+-------------+----------+" << endl;
    cout << "|   Date     | Temperature | Humidity |" << endl;
    cout << "+------------+-------------+----------+" << endl;

    // Displaying all records in table format
    for (const auto& record : records) {
        cout << "| " << record.date.toString() << " | "
             << record.temperature << "        | "
             << record.humidity << "       |" << endl;
        cout << "+------------+-------------+----------+" << endl;
    }
}

