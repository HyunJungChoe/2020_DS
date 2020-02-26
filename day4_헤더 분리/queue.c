#include "queue.h"
Tree* Queue[QUEUE_SIZE];
int front, rear;
void init_queue(void){
    front = rear = 0;
}
void clear_queue(void) {
    front = rear; //차있는곳 = 비어있는곳
}
void put(Tree* data)
{
    if (rear + 1 == front)
    {
        puts("queue overflow");
        return;// void함수를 그냥 종료 할 때
    }
    Queue[rear++] = data;
    //if (rear == 5)
    //    rear = 0;
    rear = rear % 5;
}
Tree* get(void)
{
    int save;
    if (front == rear)
    {
        puts("queue empty");
        return -1;
    }
    save = front;
    front = ++front % 5;
    return Queue[save];
    
}
int queue_empty(void) {
    return (front == rear) ? 0 : 1; //비어있으면 0, 아니면 1
}