#pragma once
#ifndef _inc_h
#define _inc_h
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _tree Tree;
struct _tree {
    int key;
    struct _tree* left;
    struct _tree* right;
};

#endif 