#pragma once
#ifndef KLACH_H
#define KLACH_H

#define K_PI 3.14159265358979323846264338327950

typedef struct Date { int year; int month; int day; } Date;
typedef struct Time { int hour; int minute; int second; } Time;
typedef struct DateTime { Date date; Time time; } DateTime;
typedef struct Coord2D { double x; double y; } Coord2D;
typedef struct Coord3D { double x; double y; double z; } Coord3D;

int IsBetween(double min, double val, double max);
int IsDigit(char ch);
int IsUpper(char ch);
int IsLower(char ch);
int IsLeapYear(int year);
int IsValidDate(Date date);
int IsValidTime(Time time);
int IsPrime(int num);

void SortAs_i(int arr[], int len);
void SortDes_i(int arr[], int len);

void DoubleSortAs_lf(double arr[], int len);
void DoubleSortDes_lf(double arr[], int len);

int GetIndex_i(int val, int arr[], int len);
int RemoveArea_i(int start, int end, int arr[], int len);
int RemoveValueAll_i(int val, int arr[], int len);
int AddValue_i(int val, int idx, int arr[], int len);

int GetIndex_lf(double val, double arr[], int len);
int RemoveArea_lf(int start, int end, double arr[], int len);
int RemoveValueAll_lf(double val, double arr[], int len);
int AddValue_lf(double val, int idx, double arr[], int len);

int GetDaysInMonth(int month, int year);
Time SecondsToTime(int seconds);
DateTime SecondsToDateTime(int seconds);
int TimeToSeconds(Time time);
int DateTimeToSeconds(DateTime dateTime);
Date DateAddDays(int days, Date date);
DateTime DateTimeAddSeconds(int seconds, DateTime dateTime);
Time TimeAddSeconds(int seconds, Time time);

#endif
