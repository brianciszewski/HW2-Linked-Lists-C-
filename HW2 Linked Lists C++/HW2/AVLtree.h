#pragma once
#ifndef LIST_H
#define LIST_H
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
struct node {
    int Data;
    node* L;
    node* R;
    int height;
};             /// AAAAAAAHHHHHHHHHHH, static.


class AVLtree {
public:

    int nodeHeight(node*);
    node* s_rotate_L(node*);
    node* s_rotate_R(node*);
    node* d_rotate_L(node*);
    node* d_rotate_R(node*);
    node* insert(node*,int D);
    
    void displayTree(node*);

    AVLtree();
    node* root;
    node* TempParent;

};

#endif