#include "Date.h"

using namespace std;
    Date::Date() : year(0), month(0), day(0) {}

    Date::Date(const string &dateStr) {
        istringstream iss(dateStr);
        char delimiter;
        iss >> year >> delimiter >> month >> delimiter >> day;
    }

    string Date::toString() const {
        ostringstream oss;
        oss << year << "-" << (month < 10 ? "0" : "") << month << "-" << (day < 10 ? "0" : "") << day;
        return oss.str();
    }
