

#ifndef SEP_DATE_H
#define SEP_DATE_H

#include <string>
#include <sstream>

namespace std {
    class Date {
    public:
        Date();
        explicit Date(const std::string &dateStr);
        std::string toString() const;

    private:
        int year, month, day;
    };
} // namespace std

#endif // DATE_H
