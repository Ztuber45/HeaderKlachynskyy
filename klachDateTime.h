#pragma once

#include "klach.h"

typedef struct Date { int year; int month; int day; } Date;
typedef struct Time { int hour; int minute; int second; } Time;
typedef struct DateTime { Date date; Time time; } DateTime;

int IsLeapYear(int year);
int IsValidDate(Date date);
int IsValidTime(Time time);

int GetDaysInMonth(int month, int year);
Time SecondsToTime(int seconds);
DateTime SecondsToDateTime(int seconds);
int TimeToSeconds(Time time);
Date DateAddDays(int days, Date date); // TODO
DateTime DateTimeAddSeconds(int seconds, DateTime dateTime); // TODO
Time TimeAddSeconds(int seconds, Time time); // TODO

int IsLeapYear(int year) {
        if (year % 4 == 0
            && (year % 100 != 0 || year % 400 == 0)) {
                return TRUE;
        }
        return FALSE;
}
int IsValidDate(Date date) {
        if (1 <= date.day && date.day <= GetDaysInMonth(date.month, date.year)) {
                return TRUE;
        }
        return FALSE;
}
int IsValidTime(Time time) {
        if ((0 <= time.hour && time.hour <= 23)
            && (0 <= time.minute && time.minute <= 59)
            && (0 <= time.second && time.second <= 59)) {
                return TRUE;
        }
        return FALSE;
}
int GetDaysInMonth(int month, int year) {
        switch (month) {
        case 2:
                return 28 + IsLeapYear(year);
                break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
                return 31;
                break;
        case 4:
        case 6:
        case 9:
        case 11:
                return 30;
                break;
        default:
                return 0;
                break;
        }
}

Time SecondsToTime(int seconds) {
        Time time;

        time.minute = seconds / 60;
        time.second = seconds % 60;
        time.hour   = time.minute / 60;
        time.minute = time.minute % 60;

        return time;
}

DateTime SecondsToDateTime(int seconds) {
        DateTime dateTime;
        int days;

        dateTime.time.minute = seconds / 60;
        dateTime.time.second = seconds % 60;
        dateTime.time.hour   = dateTime.time.minute / 60;
        dateTime.time.minute = dateTime.time.minute % 60;

        days = dateTime.time.hour / 24;
        dateTime.time.hour = dateTime.time.hour % 24;

        dateTime.date.day   = 1;
        dateTime.date.month = 1;
        dateTime.date.year  = 0;

        for (days = days; days > 0; days--) {
                dateTime.date.day++;
                if (dateTime.date.day > GetDaysInMonth(dateTime.date.month, dateTime.date.year)) {
                        dateTime.date.month++;
                        dateTime.date.day = 1;
                }
                if (dateTime.date.month > 12) {
                        dateTime.date.year++;
                        dateTime.date.month = 1;
                        dateTime.date.day = 1;
                }
        }

        return dateTime;
}

int TimeToSeconds(Time time) {
        int seconds =
                time.hour * 3600
                + time.minute * 60
                + time.second;

        return seconds;
}

Date DateAddDays(int days, Date date) {
}

DateTime DateTimeAddSeconds(int seconds, DateTime dateTime) {
}

Time TimeAddSeconds(int seconds, Time time) {
}
