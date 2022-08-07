//
// Created by pcx on 8/7/2022.
//

#include "u_linkedList.h"
#include "stdlib.h"

void printList(node_T *head)
{
    node_T *temp = head;
    while(temp->next != NULL)
    {

    }
}

node_T * uNode_createNode(U_LINKEDLIST_DATA_TYPE value)
{
    node_T * node_ptr = malloc(sizeof(node_T));
    node_ptr->data = value;
    node_ptr->next = (node_T*)NULL;
    return node_ptr;
}
node_T * uNode_installAtHead(node_T **head_pptr, node_T *noteInstalled)
{
    noteInstalled->next = *head_pptr;
    *head_pptr = (node_T *) noteInstalled;
    return noteInstalled;
}


