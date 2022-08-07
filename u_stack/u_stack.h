//
// Created by pcx on 8/7/2022.
//

#ifndef C17TEST_U_STACK_H
#define C17TEST_U_STACK_H

#include <stdint.h>


#define MAX_SIZE_OF_STACK 10
#define pd_BOOL_T uint8_t
#define STACK_EMPTY (-1)
#define STACK_DATA_TYPE uint32_t


enum stk_operationStatus
{
    empty = -1,
    full = MAX_SIZE_OF_STACK - 1,
};

typedef enum stk_operationStatus stk_operationStatus_T;

struct stack
{
    uint32_t data[MAX_SIZE_OF_STACK];
    int16_t top;
};
typedef struct stack stk_T;


stk_operationStatus_T createEmptyStack(stk_T *stack_ptr);
stk_operationStatus_T stack_isFull(stk_T *stack_ptr);
pd_BOOL_T stack_isEmpty(stk_T *stack_ptr);
stk_operationStatus_T push(stk_T *this, STACK_DATA_TYPE element);

#endif //C17TEST_U_STACK_H
