//
// Created by hoang on 8/10/2022.
//

#include "u_queue.h"

/* u_queue Methods */
void u_queue_constructor(u_queue_T *queueObj_ptr,U_QUEUE_DATA_TYPE *array, uint32_t numberOfElements, void (*overLoadHandler)(),void (*underFlowHandler)())
{
    queueObj_ptr->storage.array_ptr = array;
    queueObj_ptr->storage.size = numberOfElements;
    queueObj_ptr->front = -1;
    queueObj_ptr->rear = -1;
    queueObj_ptr->overLoadHandler = overLoadHandler;
    queueObj_ptr->underFlowHandler = underFlowHandler;
}

void u_queue_enqueue(u_queue_T *queueObj_ptr, uint32_t data) {
    if(queueObj_ptr->rear == queueObj_ptr->storage.size - 1)
    {
        //todo: Write OVERFLOW
    }
    else
    {
        if(((-1 == queueObj_ptr->front) && (-1 == queueObj_ptr->rear)))
        {  queueObj_ptr->front = 0;
            queueObj_ptr->rear = 0;
        }
        else
        {
            queueObj_ptr->rear ++;
        }
        queueObj_ptr->storage.array_ptr[queueObj_ptr->rear] = data;
    }

}

U_QUEUE_DATA_TYPE u_queue_dequeue(u_queue_T *queueObj_ptr) {
    return 0;
}
