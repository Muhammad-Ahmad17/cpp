#include "OutlierAnalysis.h"
#include <cmath>

using namespace std;

    vector<pair<Date, double>> OutlierAnalysis::detectOutliers(double threshold) {
        if (records.empty()) return {};

        double mean = 0.0, variance = 0.0;
        for (const auto &record : records) mean += record.temperature;
        mean /= records.size();
        for (const auto &record : records) variance += (record.temperature - mean) * (record.temperature - mean);
        variance /= records.size();
        double stdDev = sqrt(variance);

        vector<pair<Date, double>> outliers;
        for (const auto &record : records) {
            if (fabs(record.temperature - mean) > threshold * stdDev) {
                outliers.emplace_back(record.date, record.temperature);
            }
        }
        return outliers;
    }

