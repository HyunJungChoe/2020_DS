#include "stack.h"
Tree* Stack[STACK_SIZE]; //����ü �����͹迭�� ���� ������ �޸𸮸� �Ƴ���.
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
    return (top <= -1) ? 0 : 1; //��������� 0, �ƴϸ� 1
}
