#ifndef __stack_object_h__
#define __stack_object_h__

#include <stddef.h> //declared NULL
#include <stdlib.h> //declared free function   calloc
typedef struct node
{
    char val;
    int rank;
    struct node *next;
}node, *Node;

int push(Node *head, Node theNode);
node pop(Node *head);
node top(Node *head);

#endif