/*******************************
 * Copyright (c) 2024          *
 *                             *
 * Name: MUHAMMAD AHMAD.       *
 *                             *
 * Project Name: PF.          *
 *                             *
 * Date: 2024-06-27.           *
 *******************************/
#include <iostream>
#include <ctime>
#include "iomanip"
using namespace std;

void currentUTC_Time ( int T_standard ){
    int hrs,mins,secs,T_secs;

    T_secs=T_standard%86400;
    // cout <<  "Today Time in secs: " <<T_secs<< endl;

    hrs=T_secs/3600;
   //  cout <<  "Today hours: " <<hrs<< endl;

    T_secs%=3600;

    mins=T_secs/60;
   // cout <<  "Today minuets: " <<mins<< endl;

    T_secs%=60;

    secs=T_secs;
   //  cout << "Today seconds: " <<secs<< endl;

    cout << setfill('0') << setw(2) <<hrs << ":"  << setw(2) << mins << ":"  << setw(2) << secs ;
}

int main() {
     /* The time() function in C++ returns the current calendar
      time that has passed since 00:00 hours, January 1, 1970,
      UTC as an object of type time_t.*/
    cout << "Current UTC time:- ";
    currentUTC_Time(time(0));

    // Pakistan Standard Time (PKT) = UTC+05:00 hrs
    cout << "\nCurrent pakistan time:- ";
     currentUTC_Time(time(0)+(5*3600));
    return 0;
}

//  X % 86400 = today total secs

//  X % 60*60 = today hr
//  X % 60    = today 60


