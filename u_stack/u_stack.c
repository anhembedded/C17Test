//
// Created by pcx on 8/7/2022.
//

#include "u_stack.h"



stk_operationStatus_T createEmptyStack(stk_T *stack_ptr, void (*EmptyHandler)(), void (*FullHandler)())
{
    stack_ptr->top = -1;
    stack_ptr->stackEmptyCallbackHandler = EmptyHandler;
    stack_ptr->stackFullCallbackHandler = FullHandler;
    return success;
}
pd_BOOL_T stk_isFull(stk_T *stack_ptr)
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
pd_BOOL_T stk_isEmpty(stk_T *stack_ptr)
{
    if (stack_ptr->top == STACK_EMPTY)
    {
        return 1;
    } else
    {
        return 0;
    }
}

stk_operationStatus_T stk_push(stk_T *this, STACK_DATA_TYPE element)
{

    if(stk_isFull(this))
    {
        this->stackFullCallbackHandler();
        return full;
    }else
    {
        pd_disableIqr();
        this->top ++;
        this->data[this->top] = element;
        pd_enableIqr();
        return success;
    }
}

stk_operationStatus_T  stk_pop(stk_T *this)
{
    if(stk_isEmpty(this))
    {
        this->stackEmptyCallbackHandler();
        return empty;
    } else
    {
        this->top --;
        return success;
    }
}
STACK_DATA_TYPE std_seek(stk_T *this)
{
    if(stk_isEmpty(this))
    {
        this->stackEmptyCallbackHandler();
    }

    return this->data[this->top];

}




