#pragma once
#ifndef _queue_h
#define _queue_h
#include "inc.h"
#define QUEUE_SIZE 5    
extern Tree* Queue[QUEUE_SIZE];
extern int front, rear;
void init_queue(void);
void clear_queue(void);
void put(Tree* data);
Tree* get(void);
int queue_empty(void);
#endif //_queue_h