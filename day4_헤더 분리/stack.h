#pragma once
#ifndef _stack_h
#define _stack_h
#include "inc.h"
#define STACK_SIZE 5    
extern Tree* Stack[STACK_SIZE]; //구조체 포인터배열로 만든 스택이 메모리를 아낀다.
extern int top;
void init_stack(void);
void push(Tree* data);
Tree* pop(void);
int stack_empty(void);
#endif //_stack_h