#ifndef OUTLIER_ANALYSIS_H
#define OUTLIER_ANALYSIS_H

#include "DataRetriever.h"
#include <vector>  // For storing outliers

namespace std {

    class OutlierAnalysis : public DataRetriever {
    public:
        // Method to detect outliers based on temperature
        std::vector<std::pair<Date, double>> detectOutliers(double threshold = 2.0);
    };

} // namespace std

#endif // OUTLIER_ANALYSIS_H
