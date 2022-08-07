/*
 * Created on Sun Aug 07 2022
 *
 *
 */

#include "u_stack.h"
#include <stdio.h>

/**
 *
 * @param  {stk_T*} stack_ptr       :
 * @param  {void(*)()} EmptyHandler :
 * @param  {void(*)()} FullHandler  :
 * @return {stk_operationStatus_T}  :
 */
stk_operationStatus_T createEmptyStack(stk_T *stack_ptr, void (*EmptyHandler)(), void (*FullHandler)())
{
    stack_ptr->top = -1;
    stack_ptr->stackEmptyCallbackHandler = EmptyHandler;
    stack_ptr->stackFullCallbackHandler = FullHandler;
    return success;
}
/**
 * @brief
 *
 *
 * @param  {stk_T*} stack_ptr :
 * @return {pd_BOOL_T}        :
 */
pd_BOOL_T stk_isFull(stk_T *stack_ptr)
{
    if (stack_ptr->top == MAX_SIZE_OF_STACK - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/**
 * @brief
 *
 *
 * @param  {stk_T*} stack_ptr :
 * @return {pd_BOOL_T}        :
 */
pd_BOOL_T stk_isEmpty(stk_T *stack_ptr)
{
    if (stack_ptr->top == STACK_EMPTY)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/**
 *
 * @param  {stk_T*} this             :
 * @param  {STACK_DATA_TYPE} element :
 * @return {stk_operationStatus_T}   :
 */
stk_operationStatus_T stk_push(stk_T *this, STACK_DATA_TYPE element)
{

    if (stk_isFull(this))
    {
        this->stackFullCallbackHandler();
        return full;
    }
    else
    {
        pd_disableIqr();
        this->data[this->top] = element;
        this->top++;
        pd_enableIqr();
        return success;
    }
}
/**
 *
 * @param  {stk_T*} this      :
 * @return {STACK_DATA_TYPE}  :
 */
STACK_DATA_TYPE stk_pop(stk_T *this)
{
    if (stk_isEmpty(this))
    {
        this->stackEmptyCallbackHandler();
        return empty;
    }
    else
    {
        return this->data[--this->top];
    }
}
/**
 * @brief
 *
 *
 * @param  {stk_T*} this      :
 * @return {STACK_DATA_TYPE}  :
 */
STACK_DATA_TYPE stk_peek(stk_T *this)
{
    if (stk_isEmpty(this))
    {
        this->stackEmptyCallbackHandler();
    }

    return this->data[(this->top - 1)];
}
/**
 *
 * @param  {stk_T*} this :
 */
void stk_printlnAllElement(stk_T *this)
{
    if (stk_isEmpty(this))
    {
        this->stackEmptyCallbackHandler();
        return;
    }
    printf("print all stack: \n");
    for (int16_t i = (int16_t)(this->top - 1); i >= 0; i--)
    {
        printf("%d \t", this->data[i]);
    }
}
