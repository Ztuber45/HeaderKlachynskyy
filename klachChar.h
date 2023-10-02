#pragma once

#include "klach.h"
#include "klachInt.h"

int IsDigit(char ch);
int IsUpper(char ch);
int IsLower(char ch);


int IsDigit(char ch) {
        if (IsBetween_i('0', ch, '9')) {
                return TRUE;
        }
        return FALSE;
}
int IsUpper(char ch) {
        if (IsBetween_i('A', ch, 'Z')) {
                return TRUE;
        }
        return FALSE;
}
int IsLower(char ch) {
        if (IsBetween_i('a', ch, 'z')) {
                return TRUE;
        }
        return FALSE;
}
