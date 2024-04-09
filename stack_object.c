#include "stack_object.h"
#include "server_dbg.h"
//堆栈对象系统
//维护目标：进入堆栈的数据一定是在堆上分配的空间
//释放空间，有堆栈对象系统来维护
//pop函数，使用值传递方式

int push(Node *head, Node theNode)
{
    check(theNode != 0,"theNode is NULL");
    theNode->next = *head;
    *head = theNode;
    return 0;
error:
    printf("push error!");
    return 1;
}

node pop(Node *head)
{
    node value = {.val=0,.rank=0,.next=NULL};
    if (*head == NULL) return value;

    value = **head;
    Node del = *head;
    *head = (*head)->next;
    free(del);
    return value;
}

node top(Node *head)
{
    node top_value = {.val=0, .rank=0, .next=NULL};
    if (*head == NULL) return top_value;

    top_value = **head;
    return top_value;
}