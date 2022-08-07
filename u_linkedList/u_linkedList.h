//
// Created by pcx on 8/7/2022.
//

#ifndef C17TEST_U_LINKEDLIST_H
#define C17TEST_U_LINKEDLIST_H
#include "u_stdint.h"
#define U_LINKEDLIST_DATA_TYPE uint16_t


typedef enum node_operationStatus node_operationStatus_T;

struct node {
    U_LINKEDLIST_DATA_TYPE data;
    struct node *next;
};

typedef struct node node_T;

node_T * uNode_createNode(U_LINKEDLIST_DATA_TYPE  value);
node_T * uNode_installAtHead(node_T **head_ptr, node_T *noteInstalled);
void printList(node_T *head);
#endif //C17TEST_U_LINKEDLIST_H
