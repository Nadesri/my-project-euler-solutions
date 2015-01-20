//
//  main.cpp
//  problem19: Counting Sundays
//
//    You are given the following information, but you may prefer to do some research for yourself.
//
//    1 Jan 1900 was a Monday.
//    Thirty days has September,
//    April, June and November.
//    All the rest have thirty-one,
//    Saving February alone,
//    Which has twenty-eight, rain or shine.
//    And on leap years, twenty-nine.
//    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
//    How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
//
//  Created by Nade Sritanyaratana on 1/19/15.
//  Copyright (c) 2015 Nade Sritanyaratana. All rights reserved.
//

#include <iostream>

void calcSundaysByYear(int year, int startingDay, int& numSundays, int& endingDay);
void calcSundays(int startingYear, int startingDay, int endingYear, int& numSundays);
void calcFirstSundaysByYear(int year, int startingDay, int& numSundays, int& endingDay);
void calcStartingDay(int initialYear, int initialStartingDay, int finalYear, int &finalStartingDay);

using namespace std;
int main(int argc, const char * argv[]) {
    int startingYear, startingDay, endingYear, numSundays;
    int& rNumSundays = numSundays;
    int& rStartingDay = startingDay;
    
    if (argc==4) {
        startingYear = atoi(argv[1]);
        startingDay = atoi(argv[2]);
        endingYear = atoi(argv[3]);
    } else {
        startingYear = 1901;
        calcStartingDay(1900, 1, startingYear, rStartingDay);
        endingYear = 2000;
    }
    
    calcSundays(startingYear, startingDay, endingYear, rNumSundays);
    
    cout << "The number of Sundays from " << startingYear << " to " << endingYear << " is ";
    cout << numSundays << endl;
    
    return 0;
}

void calcSundays(int startingYear, int startingDay, int endingYear, int& numSundays) {
    numSundays = 0;
    for (int i=startingYear; i<=endingYear; i++) {
        int numSundaysByYear, endingDay;
        int& rNumSundaysByYear = numSundaysByYear;
        int& rEndingDay = endingDay;
        
        calcFirstSundaysByYear(i, startingDay, rNumSundaysByYear, rEndingDay);
        
        numSundays += numSundaysByYear;
        startingDay = endingDay;
    }
}

/***********************************************
*   calcSundaysByYear calculates the number of 
*   Sundays for a given year.
*
*   void calcSundaysByYear(int year, int startingDay, int& numSundays, int& endingDay)
*
*   year takes on any 4 digit integer value indicating a year.
*
*   startingDay takes the following possible values:
*   0 - Sunday
*   1 - Monday
*   2 - Tuesday
*   3 - Wednesday
*   4 - Thursday
*   5 - Friday
*   6 - Saturday
*
*   numSundays is a reference to an int, to fill in the number of Sundays.
*   endingDay is a reference to an int, to fill in the endingDay for that year.
*
*   Note that endingDay takes on the same day specifications as startingDay.
***********************************************/
void calcSundaysByYear(int year, int startingDay, int& numSundays, int& endingDay) {
    int numDaysThisYear = 365;
    
    if ((year%400==0) ||                // a century divisible by 400
        (year%100!=0 && year%4==0)) {   // a non-century year divisible by 4
        numDaysThisYear++;              // Increment numDaysThisYear, since it's a leap year!
    }
    
    numSundays = (numDaysThisYear - (7-startingDay))/7;
    endingDay  = (numDaysThisYear - (7-startingDay))%7;
}

/***********************************************
 *   calcFirstSundaysByYear calculates the number of
 *   Sundays that fall on the 1st of a month for 
 *   a given year.
 *
 *   void calcFirstSundaysByYear(int year, int startingDay, int& numSundays, int& endingDay)
 *
 *   year takes on any 4 digit integer value indicating a year.
 *
 *   startingDay takes the following possible values:
 *   0 - Sunday
 *   1 - Monday
 *   2 - Tuesday
 *   3 - Wednesday
 *   4 - Thursday
 *   5 - Friday
 *   6 - Saturday
 *
 *   numSundays is a reference to an int, to fill in the number of Sundays.
 *   endingDay is a reference to an int, to fill in the endingDay for that year.
 *
 *   Note that endingDay takes on the same day specifications as startingDay.
 ***********************************************/
void calcFirstSundaysByYear(int year, int startingDay, int& numSundays, int& endingDay) {
    int numDaysThisYear = 365;
    int numDaysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    numSundays = 0;
    
    if ((year%400==0) ||                // a century divisible by 400
        (year%100!=0 && year%4==0)) {   // a non-century year divisible by 4
        numDaysThisYear++;              // Increment numDaysThisYear, since it's a leap year!
        numDaysPerMonth[1]++;
    }
    
    for (int i=0; i<12; i++) {
        if (startingDay==0) {
            numSundays++;
        }
        startingDay = (numDaysPerMonth[i] - (7-startingDay))%7;
    }
    
    endingDay  = startingDay;
}

void calcStartingDay(int initialYear, int initialStartingDay, int finalYear, int &finalStartingDay) {
    
    int startingDay = initialStartingDay;
    
    for (int year=initialYear; year<finalYear; year++) {
        int numDaysThisYear = 365;
        if ((year%400==0) ||                // a century divisible by 400
            (year%100!=0 && year%4==0)) {   // a non-century year divisible by 4
            numDaysThisYear++;              // Increment numDaysThisYear, since it's a leap year!
        }
        
        startingDay = (numDaysThisYear - (7-startingDay))%7;
    }
    
    finalStartingDay = startingDay;

}