#pragma once
#ifndef _stack_h
#define _stack_h
#include "inc.h"
#define STACK_SIZE 5    
extern Tree* Stack[STACK_SIZE]; //����ü �����͹迭�� ���� ������ �޸𸮸� �Ƴ���.
extern int top;
void init_stack(void);
void push(Tree* data);
Tree* pop(void);
int stack_empty(void);
#endif //_stack_h