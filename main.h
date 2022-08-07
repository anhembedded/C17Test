//
// Created by pcx on 8/7/2022.
//

#ifndef C17TEST_MAIN_H
#define C17TEST_MAIN_H

#include <stdint.h>
#include <stdio.h>

#include "ChiChi/220805.h"

void stackEmptyHandler();
void stackFullHandler();
void reverseArray(uint16_t *inputArray, uint16_t numberOfElements, stk_T *stackStorage);

#endif //C17TEST_MAIN_H
