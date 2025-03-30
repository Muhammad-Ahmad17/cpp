#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <stdexcept>
#include <ctime>

class WeatherData {
public:
    WeatherData(const std::string& location, time_t timestamp,
                double temperature, double humidity, double precipitation)
            : m_location(location), m_timestamp(timestamp),
              m_temperature(temperature), m_humidity(humidity),
              m_precipitation(precipitation) {}

    std::string getLocation() const { return m_location; }
    time_t getTimestamp() const { return m_timestamp; }
    double getTemperature() const { return m_temperature; }
    double getHumidity() const { return m_humidity; }
    double getPrecipitation() const { return m_precipitation; }

    static WeatherData fromCSV(const std::string& csvLine) {
        std::istringstream ss(csvLine);
        std::string location, timestampStr;
        double temperature, humidity, precipitation;

        if (std::getline(ss, location, ',') &&
            std::getline(ss, timestampStr, ',') &&
            ss >> temperature &&
            ss.ignore() &&
            ss >> humidity &&
            ss.ignore() &&
            ss >> precipitation) {

            time_t timestamp = std::stoi(timestampStr);
            return WeatherData(location, timestamp, temperature, humidity, precipitation);
        }

        throw std::runtime_error("Invalid CSV line format");
    }

private:
    std::string m_location;
    time_t m_timestamp;
    double m_temperature;
    double m_humidity;
    double m_precipitation;
};

class WeatherAnalyzer {
public:
    // Load data from CSV file
    static std::vector<WeatherData> loadData(const std::string& filename) {
        std::vector<WeatherData> data;
        std::ifstream file(filename);

        if (!file.is_open()) {
            throw std::runtime_error("Unable to open file: " + filename);
        }

        // Skip header line
        std::string headerLine;
        std::getline(file, headerLine);

        std::string line;
        while (std::getline(file, line)) {
            try {
                WeatherData weatherRecord = WeatherData::fromCSV(line);
                data.push_back(weatherRecord);
            }
            catch (const std::exception& e) {
                std::cerr << "Error parsing line: " << line
                          << " - " << e.what() << std::endl;
            }
        }

        file.close();
        return data;
    }

    // Compute average temperature
    static double computeAverageTemperature(const std::vector<WeatherData>& data) {
        if (data.empty()) return 0.0;

        double sum = std::accumulate(data.begin(), data.end(), 0.0,
                                     [](double acc, const WeatherData& wd) {
                                         return acc + wd.getTemperature();
                                     });

        return sum / data.size();
    }

    // Find highest temperature record
    static WeatherData findHighestTemperature(const std::vector<WeatherData>& data) {
        if (data.empty())
            throw std::runtime_error("Empty dataset");

        return *std::max_element(data.begin(), data.end(),
                                 [](const WeatherData& a, const WeatherData& b) {
                                     return a.getTemperature() < b.getTemperature();
                                 });
    }

    // Detect temperature anomalies using Z-score method
    static std::vector<WeatherData> detectTemperatureAnomalies(
            const std::vector<WeatherData>& data,
            double threshold = 2.0
    ) {
        std::vector<WeatherData> anomalies;
        if (data.empty()) return anomalies;

        // Calculate mean
        double mean = computeAverageTemperature(data);

        // Calculate standard deviation
        double sumSquaredDiff = std::accumulate(data.begin(), data.end(), 0.0,
                                                [mean](double acc, const WeatherData& wd) {
                                                    double diff = wd.getTemperature() - mean;
                                                    return acc + (diff * diff);
                                                });
        double stdDev = std::sqrt(sumSquaredDiff / (data.size() - 1));

        // Detect anomalies
        for (const auto& record : data) {
            double zScore = std::abs((record.getTemperature() - mean) / stdDev);
            if (zScore > threshold) {
                anomalies.push_back(record);
            }
        }

        return anomalies;
    }

    // Display analysis results
    static void displayAnalysis(const std::vector<WeatherData>& data) {
        // Print header
        std::cout << "===== Weather Data Analysis =====" << std::endl;

        // Average Temperature
        double avgTemp = computeAverageTemperature(data);
        std::cout << "Average Temperature: "
                  << std::fixed << std::setprecision(2)
                  << avgTemp << " °C" << std::endl;

        // Highest Temperature
        WeatherData highestTemp = findHighestTemperature(data);
        std::cout << "Highest Temperature: "
                  << highestTemp.getTemperature() << " °C "
                  << "at " << highestTemp.getLocation() << std::endl;

        // Temperature Anomalies
        std::vector<WeatherData> anomalies = detectTemperatureAnomalies(data);
        std::cout << "\nTemperature Anomalies:" << std::endl;
        if (anomalies.empty()) {
            std::cout << "No significant temperature anomalies detected." << std::endl;
        } else {
            for (const auto& anomaly : anomalies) {
                std::cout << "Location: " << anomaly.getLocation()
                          << ", Temperature: " << anomaly.getTemperature() << " °C"
                          << std::endl;
            }
        }
    }
};

// Sample CSV generation function (optional)
void generateSampleWeatherData(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to create sample data file");
    }

    // Write CSV header
    file << "Location,Timestamp,Temperature,Humidity,Precipitation" << std::endl;

    // Generate some sample data
    std::vector<std::string> locations = {
            "New York", "Los Angeles", "Chicago", "Houston", "Phoenix"
    };

    // Seed for somewhat random data
    srand(time(nullptr));

    for (const auto& location : locations) {
        for (int i = 0; i < 10; ++i) {
            time_t timestamp = time(nullptr) - (i * 86400); // Vary by days
            double temperature = (rand() % 600 - 100) / 10.0; // Range -10 to 50
            double humidity = 20 + (rand() % 60);
            double precipitation = (rand() % 100) / 10.0;

            file << location << ","
                 << timestamp << ","
                 << temperature << ","
                 << humidity << ","
                 << precipitation << std::endl;
        }
    }

    file.close();
}

int main() {
    try {
        // Generate sample weather data file
        const std::string SAMPLE_DATA_FILE = "weather_data.csv";
        generateSampleWeatherData(SAMPLE_DATA_FILE);

        // Load and analyze weather data
        std::vector<WeatherData> weatherData = WeatherAnalyzer::loadData(SAMPLE_DATA_FILE);

        // Display analysis results
        WeatherAnalyzer::displayAnalysis(weatherData);

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}