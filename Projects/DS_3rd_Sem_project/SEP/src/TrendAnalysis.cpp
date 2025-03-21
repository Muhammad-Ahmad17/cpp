#include "TrendAnalysis.h"

using namespace std;
    // Accessor function for records
    vector<WeatherRecord> TrendAnalysis::getRecords() const {
        return records;
    }

    vector<pair<Date, string>> TrendAnalysis::analyzeDailyTrend() {
        vector<pair<Date, string>> dailyTrends;
        const auto& records = getRecords();  // Access the records

        for (size_t i = 1; i < records.size(); ++i) {
            if (records[i].temperature > records[i - 1].temperature) {
                dailyTrends.emplace_back(records[i].date, "Increase");
            } else if (records[i].temperature < records[i - 1].temperature) {
                dailyTrends.emplace_back(records[i].date, "Decrease");
            } else {
                dailyTrends.emplace_back(records[i].date, "No Change");
            }
        }
        return dailyTrends;
    }

    string TrendAnalysis::analyzeOverallTrend() {
        const auto& records = getRecords();  // Access the records
        if (records.empty()) return "No data to analyze.";

        int increaseCount = 0, decreaseCount = 0, noChangeCount = 0;
        for (size_t i = 1; i < records.size(); ++i) {
            if (records[i].temperature > records[i - 1].temperature) {
                increaseCount++;
            } else if (records[i].temperature < records[i - 1].temperature) {
                decreaseCount++;
            } else {
                noChangeCount++;
            }
        }

        if (increaseCount > decreaseCount) {
            return "Overall Trend: Increase";
        } else if (decreaseCount > increaseCount) {
            return "Overall Trend: Decrease";
        } else {
            return "Overall Trend: No Change";
        }
    }
