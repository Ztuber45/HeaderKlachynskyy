#include "klach.h"

int IsBetween(double min, double val, double max);
int IsDigit(char ch);
int IsUpper(char ch);
int IsLower(char ch);
int IsLeapYear(int year);
int IsValidDate(Date date);
int IsValidTime(Time time);
int IsPrime(int num);

int GetIndex_i(int val, int arr[], int len);
int RemoveArea_i(int start, int end, int arr[], int len);
int RemoveValueAll_i(int val, int arr[], int len);
int AddValue_i(int val, int idx, int arr[], int len);

int GetIndex_lf(double val, double arr[], int len);
int RemoveArea_lf(int start, int end, double arr[], int len);
int RemoveValueAll_lf(double val, double arr[], int len);
int AddValue_lf(double val, int idx, double arr[], int len);

int GetDaysInMonth(int month, int year);
Time SecondsToTime(int seconds); // TODO
DateTime SecondsToDateTime(int seconds); // TODO
int TimeToSeconds(Time time); // TODO
int DateTimeToSeconds(DateTime dateTime); // TODO
Date DateAddDays(int days, Date date); // TODO
DateTime DateTimeAddSeconds(int seconds, DateTime dateTime); // TODO
Time TimeAddSeconds(int seconds, Time time); // TODO



int IsBetween(double min, double val, double max) {
        if (min <= val && val <= max) {
                return 1;
        }
        return 0;
}
int IsDigit(char ch) {
        if (IsBetween('0', ch, '9')) {
                return 1;
        }
        return 0;
}
int IsUpper(char ch) {
        if (IsBetween('A', ch, 'Z')) {
                return 1;
        }
        return 0;
}
int IsLower(char ch) {
        if (IsBetween('a', ch, 'z')) {
                return 1;
        }
        return 0;
}
int IsLeapYear(int year) {
        if (year % 4 == 0
            && (year % 100 != 0 || year % 400 == 0)) {
                return 1;
        }
        return 0;
}
int IsValidDate(Date date) {
        if (IsBetween(1, date.day, GetDaysInMonth(date.month, date.year))) {
                return 1;
        }
        return 0;
}
int IsValidTime(Time time) {
        if (IsBetween(0, time.hour, 23)
            && IsBetween(0, time.minute, 59)
            && IsBetween(0, time.second, 59)) {
                return 1;
        }
        return 0;
}
int IsPrime(int num) {
        int i;

        if (num <= 1) {
                return 0;
        }
        if (num == 2) {
                return 1;
        }
        if (num % 2 == 0) {
                return 0;
        }
        
        for (i = 3; i * i <= num; i += 2) {
                if (num % i == 0) {
                        return 0;
                }
        }
        return 1;
}

void SortAs_i(int arr[], int len) {
        int i1, i2, min;

        for (i1 = 0; i1 < len-1; i1++) {
                min = i1;
                for (i2 = i1+1; i2 < len; i2++) {
                        if (arr[i2] < arr[min]) {
                                min = i2;
                        }
                }

                if (min != i1) {
                        arr[i1] = arr[i1] + arr[min];
                        arr[min]  = arr[i1] - arr[min];
                        arr[i1] = arr[i1] - arr[min];
                }
        }
}
void SortDes_i(int arr[], int len) {
        int i1, i2, min;

        for (i1 = 0; i1 < len-1; i1++) {
                min = i1;
                for (i2 = i1+1; i2 < len; i2++) {
                        if (arr[i2] > arr[min]) {
                                min = i2;
                        }
                }

                if (min != i1) {
                        arr[i1] = arr[i1] + arr[min];
                        arr[min]  = arr[i1] - arr[min];
                        arr[i1] = arr[i1] - arr[min];
                }
        }
}

int GetIndex_i(int val, int arr[], int len) {
        int i;

        for (i = 0; i < len; i++) {
                if (arr[i] == val) {
                        return i;
                }
        }
        return 0;
}
int RemoveArea_i(int start, int end, int arr[], int len) {
        int qtyRemoved = (end - start) + 1;
        
        if (!IsBetween(0, end, len-1) || end < start) {
                return 0;
        }

        for (start = start, end = end; end < len; start++, end++) {
                arr[start] = arr[end+1];
        }
        return qtyRemoved;
}
int RemoveValueAll_i(int val, int arr[], int len) {
        int i;
        int lenBefore, qtyRemoved;

        for (i = 0; i < len; i++) {
                if (arr[i] == val) {
                        qtyRemoved = RemoveArea_i(i, i, arr, len);
                        len -= qtyRemoved;
                }
        }
        qtyRemoved = lenBefore - len;
        return qtyRemoved;
}
int AddValue_i(int val, int idx, int arr[], int len) {
        int i;

        if (idx > len) {
                return -1;
        }

        for (i = len; i > idx; i--) {
                arr[i] = arr[i-1];
        }
        arr[idx] = val;
        return 0;
}

void SortAs_lf(double arr[], int len) {
        int i1, i2, min;

        for (i1 = 0; i1 < len-1; i1++) {
                min = i1;
                for (i2 = i1+1; i2 < len; i2++) {
                        if (arr[i2] < arr[min]) {
                                min = i2;
                        }
                }

                if (min != i1) {
                        arr[i1] = arr[i1] + arr[min];
                        arr[min]  = arr[i1] - arr[min];
                        arr[i1] = arr[i1] - arr[min];
                }
        }
}
void SortDes_lf(double arr[], int len) {
        int i1, i2, min;

        for (i1 = 0; i1 < len-1; i1++) {
                min = i1;
                for (i2 = i1+1; i2 < len; i2++) {
                        if (arr[i2] > arr[min]) {
                                min = i2;
                        }
                }

                if (min != i1) {
                        arr[i1] = arr[i1] + arr[min];
                        arr[min]  = arr[i1] - arr[min];
                        arr[i1] = arr[i1] - arr[min];
                }
        }
}
int GetIndex_lf(double val, double arr[], int len) {
        int i;

        for (i = 0; i < len; i++) {
                if (arr[i] == val) {
                        return i;
                }
        }
        return 0;
}
int RemoveArea_lf(int start, int end, double arr[], int len) {
        int qtyRemoved = (end - start) + 1;
        
        if (!IsBetween(0, end, len-1) || end < start) {
                return 0;
        }

        for (start = start, end = end; end < len; start++, end++) {
                arr[start] = arr[end+1];
        }
        return qtyRemoved;
}
int RemoveValueAll_lf(double val, double arr[], int len) {
        int i;
        int lenBefore, qtyRemoved;

        for (i = 0; i < len; i++) {
                if (arr[i] == val) {
                        qtyRemoved = RemoveArea_lf(i, i, arr, len);
                        len -= qtyRemoved;
                }
        }
        qtyRemoved = lenBefore - len;
        return qtyRemoved;
}
int AddValue_lf(double val, int idx, double arr[], int len) {
        int i;

        if (idx > len) {
                return -1;
        }

        for (i = len; i > idx; i--) {
                arr[i] = arr[i-1];
        }
        arr[idx] = val;
        return 0;
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
