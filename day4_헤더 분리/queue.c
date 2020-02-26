#include "queue.h"
Tree* Queue[QUEUE_SIZE];
int front, rear;
void init_queue(void){
    front = rear = 0;
}
void clear_queue(void) {
    front = rear; //���ִ°� = ����ִ°�
}
void put(Tree* data)
{
    if (rear + 1 == front)
    {
        puts("queue overflow");
        return;// void�Լ��� �׳� ���� �� ��
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
    return (front == rear) ? 0 : 1; //��������� 0, �ƴϸ� 1
}