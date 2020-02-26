#include "stack.h"
Tree* Stack[STACK_SIZE]; //구조체 포인터배열로 만든 스택이 메모리를 아낀다.
int top;
void init_stack(void) {
    top = -1;// top=0;
}
void push(Tree* data) {
    if (top >= STACK_SIZE - 1) {
        puts("stack overflow");
        return;
    }
    Stack[++top] = data;
}
Tree* pop(void) {
    if (top <= -1)
    {
        puts("stack underflow");
        return NULL;
    }
    return Stack[top--];
}
int stack_empty(void) {
    return (top <= -1) ? 0 : 1; //비어있으면 0, 아니면 1
}
