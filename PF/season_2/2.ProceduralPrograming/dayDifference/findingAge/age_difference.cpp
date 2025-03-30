///*******************************
// * Copyright (c) 2024          *
// *                             *
// * Name: MUHAMMAD AHMAD.       *
// *                             *
// * Project Name: PF.           *
// *                             *
// * Date: 2024-06-24.           *
// *******************************/
//
//#include <iostream>
//using namespace std;
//
//bool isValidDate(int,int,int);
//bool isGreaterEqualDate (int,int,int,int,int,int);
//int daysInMonth (int month,int year);
//
//int main() {
//    int days,months,years,
//            dob,mob,yob,
//            dod,mod,yod;
//    bool valid;
////...
//    bool isGreaterEqualDate (int dob,int mob,int yob,
//                             int dod,int mod,int yod,int);
//
//    cout << "Date of birth\n";
//    do {
//        cout << "Your date of birth: ";
//        cin >> dob >> mob >> yob ;
//        if (!isValidDate(dob,mob,yob)){
//            cerr << "\nInvalid date na dal bahi ...";
//        }
//    }
//    while (!isValidDate(dob,mob,yob));
////...
//    cout << "Date of death:\n";
//    do {
//        cout << "Your expected date of death: ";
//        cin >> dod >> mod >> yod ;
//        if (!isValidDate(dod,mod,yod)){
//            cerr << "Invalid date na dal bahi ...";
//        }
//    }
//    while (!isValidDate(dod,mod,yod));
////...
//    days = dod - dob;
//    if (days < 0) {
//        days += daysInMonth(mod-1 , yod);
//        mod--;
//    }
//    months = mod - mob;
//    if (months < 0){
//        months += 12;
//        yod--;
//    }
//    years = yod - yob;
//
//    cout << "You live for:" << years << "years " << months << "months " << days << "days " <<  endl ;
//
//
//    return 0;
//}
//
//bool isValidDate(int day, int month, int year) {
//    if (month < 1 || month > 12)
//        return false;
//    if (day < 1 || day > daysInMonth(month, year))
//        return false;
//    if (year < 0)
//        return false;
//    return true;
//}
//
//bool isGreaterEqualDate (int dL,int mL,int yL,
//                         int dR,int mR,int yR){
//    if (yL>yR)
//        return true;
//    if (yL<yR)
//        return false;
//    if (mL>mR)
//        return true;
//    if (mL<mR)
//        return false;
//    return dL >= dR;
//}
//
//int daysInMonth(int month, int year) {
//    switch (month) {
//        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
//            return 31;
//        case 4: case 6: case 9: case 11:
//            return 30;
//        case 2:
//            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//                return 29;
//            else
//                return 28;
//        default:
//            return 0;
//    }
//}


/******************************
 * Copyright (c) 2024          *
 *                             *
 * Name: MUHAMMAD AHMAD.       *
 *                             *
 * Project Name: PF.           *
 *                             *
 * Date: 2024-06-24.           *
 *******************************/


#include <iostream>
using namespace std;

bool isValidDate(int, int, int);
int daysInMonth(int, int);

int main() {
    int days, months, years;
    int dob, mob, yob;
    int dod, mod, yod;

    // Input Date of Birth
    cout << "Date of birth (dd mm yyyy): ";
    while (true) {
        cin >> dob >> mob >> yob;
        if (!isValidDate(dob, mob, yob)) {
            cerr << "\nInvalid date. Please enter a valid date: ";
        } else {
            break;
        }
    }

    // Input Date of Death
    cout << "Date today (dd mm yyyy): ";
    while (true) {
        cin >> dod >> mod >> yod;
        if (!isValidDate(dod, mod, yod)) {
            cerr << "\nInvalid date. Please enter a valid date: ";
        } else {
            break;
        }
    }

    // Calculate the duration in days, months, and years
    days = dod - dob;
    if (days < 0) {
        mod--;
        days += daysInMonth(mod, yod);
    }

    months = mod - mob;
    if (months < 0) {
        yod--;
        months += 12;
    }

    years = yod - yob;

    cout << "You lived for: " << years << " years, " << months << " months, " << days << " days." << endl;

    return 0;
}

bool isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > daysInMonth(month, year)) return false;
    if (year < 0) return false;
    return true;
}
int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                return 29;
            else
                return 28;
        default:
            return 0;
    }
}

