#include <iostream>
#include "TrendAnalysis.h"
#include "StatsAnalysis.h"
#include "OutlierAnalysis.h"
#include <string>
#include <iomanip>

using namespace std;

int main() {

    const int consoleWidth = 100; // Define a width for the console page

    // Top Section
    cout << setw(consoleWidth) << "+-------------+--------------+--------------+-----------+" << "\n";
    cout << setw(consoleWidth) << "|                 Data Structure PROJECT                |" << "\n";
    cout << setw(consoleWidth) << "+-------------+--------------+--------------+-----------+" << "\n";
    cout << setw(consoleWidth) << "|                  WEATHER ANALYSIS TOOL                |" << "\n";
    cout << setw(consoleWidth) << "+-------------+--------------+--------------+-----------+" << "\n";

    // Team Members Section
    cout << "\n" << setw(consoleWidth) << "===================== TEAM MEMBERS ======================" << "\n";
    cout << setw(consoleWidth) << "---------------------------------------------------------" << "\n";
    cout << setw(consoleWidth) << "   Muhammad Ahmad (FA23-BCE-113)                         " << "\n";
    cout << setw(consoleWidth) << "---------------------------------------------------------" << "\n";

    // Predefined file name
    string fileName = "../data/weather_data.csv";
1
    // Objects for retrieving data and performing analyses
    DataRetriever retriever;
    if (!retriever.loadData(fileName)) {
        cerr << "Error: Could not open the file \"" << fileName << "\". Please check if the file exists and the path is correct.\n";
        return 1; // Exit with error code
    }

    TrendAnalysis trendAnalysis;
    trendAnalysis.loadData(fileName); // Assumes loadData handles its own file check

    StatsAnalysis statsAnalysis;
    statsAnalysis.loadData(fileName); // Assumes loadData handles its own file check

    OutlierAnalysis outlierAnalysis;
    outlierAnalysis.loadData(fileName); // Assumes loadData handles its own file check

    int choice;
    do {
        cout << "\n\n======================== MENU ===========================\n";
        cout << "\n";
        cout << "1. Show All Records                                       \n";
        cout << "---------------------------------------------------------\n";
        cout << "2. Analyze Daily Trends                                   \n";
        cout << "---------------------------------------------------------\n";
        cout << "3. Compute Statistics (Max, Min, Average)                \n";
        cout << "---------------------------------------------------------\n";
        cout << "4. Detect Outliers                                        \n";
        cout << "---------------------------------------------------------\n";
        cout << "5. Add New Record                                         \n";
        cout << "---------------------------------------------------------\n";
        cout << "6. Save Data to File                                      \n";
        cout << "---------------------------------------------------------\n";
        cout << "7. Exit                                                  \n\n";
        cout << "=========================================================\n";
        cout << "Enter your choice:  ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nAll Records:\n";
                retriever.showAllRecords(); // Display all records
                break;
            }
            case 2: {
                cout << "\nDaily Trends:\n";
                for (const auto &trend : trendAnalysis.analyzeDailyTrend()) {
                    cout << trend.first.toString() << ": " << trend.second << "\n";
                }
                cout << "\nOverall Trend: " << trendAnalysis.analyzeOverallTrend() << "\n";
                break;
            }
            case 3: {
                cout << "\nStatistics Analysis:\n";
                auto [maxDate, maxTemp, minDate, minTemp, avgTemp] = statsAnalysis.computeStats();
                cout << "Max Temperature: " << maxTemp << " on " << maxDate.toString() << "\n";
                cout << "Min Temperature: " << minTemp << " on " << minDate.toString() << "\n";
                cout << "Average Temperature: " << avgTemp << "\n";
                break;
            }
            case 4: {
                cout << "\nOutlier Analysis:\n";
                for (const auto &outlier : outlierAnalysis.detectOutliers()) {
                    cout << outlier.first.toString() << ": " << outlier.second << "\n";
                }
                break;
            }
            case 5: {
                cout << "\nAdd New Record:\n";
                string dateStr;
                double temperature, humidity;
                cout << "Enter date (YYYY-MM-DD): ";
                cin >> dateStr;
                cout << "Enter temperature: ";
                cin >> temperature;
                cout << "Enter humidity: ";
                cin >> humidity;
                retriever.addRecord(Date(dateStr), temperature, humidity);
                cout << "Record added successfully!\n";
                break;
            }
            case 6: {
                retriever.saveToFile(fileName);
                cout << "Data saved successfully to " << fileName << "\n";
                break;
            }
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 7);

    return 0;
}
