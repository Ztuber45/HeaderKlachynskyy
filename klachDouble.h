#pragma once

#include "klach.h"

int IsBetween_d(double min, double val, double max);

void SortAs_d(double arr[], int len);
void SortDes_d(double arr[], int len);

int GetBiggestValue_d(double arr[], int len);

int GetIndex_d(double val, double arr[], int len);
int RemoveArea_d(int start, int end, double arr[], int len);
int RemoveValueAll_d(double val, double arr[], int len);
int AddValue_d(double val, int idx, double arr[], int len);

int IsBetween_d(double min, double val, double max) {
        if (min <= val && val <= max) {
                return TRUE;
        }
        return FALSE;
}

void SortAs_d(double arr[], int len) {
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

void SortDes_d(double arr[], int len) {
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

int GetBiggestValue_d(double arr[], int len) {
        int idx;
        double biggest = arr[0];

        for (idx = 1; idx < len; idx++) {
                if (arr[idx] > biggest) {
                        biggest = arr[idx];
                }
        }
        return biggest;
}

int GetIndex_d(double val, double arr[], int len) {
        int i;

        for (i = 0; i < len; i++) {
                if (arr[i] == val) {
                        return i;
                }
        }
        return NONE;
}

int RemoveArea_d(int start, int end, double arr[], int len) {
        int qtyRemoved = (end - start) + 1;
        
        if (!IsBetween_d(0, end, len-1) || end < start) {
                return 0;
        }

        for (start = start, end = end; end < len; start++, end++) {
                arr[start] = arr[end+1];
        }
        return qtyRemoved;
}

int RemoveValueAll_d(double val, double arr[], int len) {
        int i;
        int lenBefore, qtyRemoved;

        for (i = 0; i < len; i++) {
                if (arr[i] == val) {
                        qtyRemoved = RemoveArea_d(i, i, arr, len);
                        len -= qtyRemoved;
                }
        }
        qtyRemoved = lenBefore - len;
        return qtyRemoved;
}

int AddValue_d(double val, int idx, double arr[], int len) {
        int i;

        if (idx > len) {
                return NONE;
        }

        for (i = len; i > idx; i--) {
                arr[i] = arr[i-1];
        }
        arr[idx] = val;
        return 0;
}
