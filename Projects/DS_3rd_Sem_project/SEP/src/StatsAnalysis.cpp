#include "StatsAnalysis.h"
#include <limits>

using namespace std;

    tuple<Date, double, Date, double, double> StatsAnalysis::computeStats() {
        if (records.empty()) return {{}, 0.0, {}, 0.0, 0.0};

        // Initialize heaps
        MinHeap minHeap;
        MaxHeap maxHeap;

        double sumTemp = 0.0;
        Date maxDate, minDate;

        // Add temperature values to heaps
        for (const auto &record : records) {
            minHeap.push(record.temperature);
            maxHeap.push(record.temperature);
            sumTemp += record.temperature;
        }

        double maxTemp = maxHeap.top();  // Largest value from MaxHeap
        double minTemp = minHeap.top();  // Smallest value from MinHeap

        // Find the corresponding dates
        for (const auto &record : records) {
            if (record.temperature == maxTemp) {
                maxDate = record.date;
            }
            if (record.temperature == minTemp) {
                minDate = record.date;
            }
        }

        double avgTemp = sumTemp / records.size();
        return {maxDate, maxTemp, minDate, minTemp, avgTemp};
    }
