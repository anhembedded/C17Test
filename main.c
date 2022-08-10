#include "main.h"
#include "file/m_file.h"
#include "string.h"
#include "u_queue/u_queue.h"

u_queue_T  myQueue;
U_QUEUE_DATA_TYPE myQueueStorage [100];
U_QUEUE_DATA_TYPE var;

int main()
{
    u_queue_constructor(&myQueue,myQueueStorage,100,pd_NOP,pd_NOP);
    for(uint32_t i=0; i < 100; i++)
    {
        u_queue_enqueue(&myQueue, i);
    }
    var = u_queue_dequeue(&myQueue);
    var = u_queue_dequeue(&myQueue);
    var = u_queue_dequeue(&myQueue);
    var = u_queue_dequeue(&myQueue);
    var = u_queue_dequeue(&myQueue);
    var = u_queue_dequeue(&myQueue);
    return 0;
}

