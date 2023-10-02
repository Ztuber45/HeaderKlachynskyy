#include "klach.h"

int IsBetween_i(int min, int val, int max);
int IsPrime(int num);

void SortAs_i(int arr[], int len);
void SortDes_i(int arr[], int len);

int GetIndex_i(int val, int arr[], int len);
int RemoveArea_i(int start, int end, int arr[], int len);
int RemoveValueAll_i(int val, int arr[], int len);
int AddValue_i(int val, int idx, int arr[], int len);

int IsBetween_i(int min, int val, int max) {
        if (min <= val && val <= max) {
                return TRUE;
        }
        return FALSE;
}

int IsPrime(int num) {
        int i;

        if (num <= 1) {
                return FALSE;
        }
        if (num == 2) {
                return TRUE;
        }
        if (num % 2 == 0) {
                return FALSE;
        }
        
        for (i = 3; i * i <= num; i += 2) {
                if (num % i == 0) {
                        return FALSE;
                }
        }
        return TRUE;
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
        return ERROR;
}

int RemoveArea_i(int start, int end, int arr[], int len) {
        int qtyRemoved = (end - start) + 1;
        
        if (!IsBetween_i(0, end, len-1) || end < start) {
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
                return ERROR;
        }

        for (i = len; i > idx; i--) {
                arr[i] = arr[i-1];
        }
        arr[idx] = val;
        return 0;
}
