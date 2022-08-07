//
// Created by pcx on 8/7/2022.
//

#include "u_stack.h"

stk_operationStatus_T createEmptyStack(stk_T *stack_ptr)
{
    stack_ptr->top = -1;
}
stk_operationStatus_T stack_isFull(stk_T *stack_ptr)
{
    if (stack_ptr->top == MAX_SIZE_OF_STACK - 1)
    {
        return 1;
    }
    else
    {
        return  0;
    }

}
pd_BOOL_T stack_isEmpty(stk_T *stack_ptr)
{
    if (stack_ptr->top == STACK_EMPTY)
    {
        return 1;
    } else
    {
        return 0;
    }
}

stk_operationStatus_T push(stk_T *this, STACK_DATA_TYPE element)
{
    if(stack_isFull(this))
    {
        //todo: return
    }else
    {
        this->top ++;
        this->data[this->top] = element;
    }
}
