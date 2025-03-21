#ifndef STATS_ANALYSIS_H
#define STATS_ANALYSIS_H

#include "DataRetriever.h"
#include "MinHeap.h"
#include "MaxHeap .h"
#include <tuple>  // For returning multiple values (max, min, average)

namespace std {

    class StatsAnalysis : public DataRetriever {
    public:
        // Method to compute statistics (max, min, average)
        tuple<Date, double, Date, double, double> computeStats();
    };

} // namespace std

#endif // STATS_ANALYSIS_H
