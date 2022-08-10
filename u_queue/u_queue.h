//
// Created by hoang on 8/10/2022.
//

#ifndef C17TEST_U_QUEUE_H
#define C17TEST_U_QUEUE_H
#include "u_stdint.h"

#define U_QUEUE_DATA_TYPE uint32_t

struct arrayStorage
{
    U_QUEUE_DATA_TYPE *array_ptr;
    uint32_t size;
};
typedef struct arrayStorage arrayStorage_T;
struct u_queue{
    int32_t front;
    int32_t rear;
    void (*overLoadHandler)();
    void (*underFlowHandler)();
    arrayStorage_T storage;
};
typedef struct u_queue u_queue_T;

/* u_queue Methods */
void u_queue_constructor(u_queue_T *queueObj_ptr,U_QUEUE_DATA_TYPE *array, uint32_t numberOfElements, void (*overLoadHandler)(),void (*underFlowHandler)());
void u_queue_enqueue(u_queue_T *queueObj_ptr, U_QUEUE_DATA_TYPE data);
U_QUEUE_DATA_TYPE u_queue_dequeue(u_queue_T *queueObj_ptr);
U_QUEUE_DATA_TYPE u_queue_peekFirst(u_queue_T *queueObj_ptr, U_QUEUE_DATA_TYPE data);
U_QUEUE_DATA_TYPE u_queue_peekLast(u_queue_T *queueObj_ptr, U_QUEUE_DATA_TYPE data);





#endif //C17TEST_U_QUEUE_H
