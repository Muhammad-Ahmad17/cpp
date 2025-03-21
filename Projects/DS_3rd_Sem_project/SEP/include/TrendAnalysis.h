#ifndef SEP_TRENDANALYSIS_H
#define SEP_TRENDANALYSIS_H

#include <vector>
#include "Date.h"
#include "DataRetriever.h"  // Include the DataRetriever header

namespace std {
    class TrendAnalysis : public DataRetriever {
    public:
        // Accessor function for records if necessary
        std::vector<WeatherRecord> getRecords() const;

        // Analyze trends
        std::vector<std::pair<Date, std::string>> analyzeDailyTrend();
        std::string analyzeOverallTrend();
    };
}

#endif
