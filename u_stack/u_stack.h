//
// Created by pcx on 8/7/2022.
//

#ifndef C17TEST_U_STACK_H
#define C17TEST_U_STACK_H

#include <stdint.h>
#include "u_stdint.h"


#define MAX_SIZE_OF_STACK 10
#define STACK_EMPTY (-1)
#define STACK_DATA_TYPE uint32_t


 enum stk_operationStatus
{
    empty = -1,
    full = MAX_SIZE_OF_STACK - 1,
    success
};

typedef enum stk_operationStatus stk_operationStatus_T;

struct stack
{
    uint32_t data[MAX_SIZE_OF_STACK];
    int16_t top;
    void (*stackEmptyCallbackHandler)();
    void (*stackFullCallbackHandler)();
};


typedef struct stack stk_T;



stk_operationStatus_T createEmptyStack(stk_T *stack_ptr, void (*EmptyHandler)(), void (*FullHandler)());
pd_BOOL_T stk_isFull(stk_T *stack_ptr);
pd_BOOL_T stk_isEmpty(stk_T *stack_ptr);
stk_operationStatus_T stk_push(stk_T *this, STACK_DATA_TYPE element);
stk_operationStatus_T  stk_pop(stk_T *this);
STACK_DATA_TYPE std_seek(stk_T *this);


#define stk_defaultConstructor ((stk_T){.top = empty})
#endif //C17TEST_U_STACK_H
