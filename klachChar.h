#pragma once

#include "klach.h"

int IsDigit(char ch);
int IsUpper(char ch);
int IsLower(char ch);

int IsBetween_c(char min, char val, char max) {
        if (min <= val && val <= max) {
                return TRUE;
        }
        return FALSE;
}

int IsDigit(char ch) {
        if (IsBetween_c('0', ch, '9')) {
                return TRUE;
        }
        return FALSE;
}
int IsUpper(char ch) {
        if (IsBetween_c('A', ch, 'Z')) {
                return TRUE;
        }
        return FALSE;
}
int IsLower(char ch) {
        if (IsBetween_c('a', ch, 'z')) {
                return TRUE;
        }
        return FALSE;
}
