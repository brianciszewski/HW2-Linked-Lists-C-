#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
#include<fstream>

#include "AVLtree.h"
#include "List.h"
#include<typeinfo>

using namespace std;



int AVLtree::nodeHeight(node* Z) {
    int returnVal = -1;
    if (Z != NULL) {
        returnVal = Z->height;
        /*
        if (Z->height == 1) {
            root->Data = Z->Data;
            root->height = Z->height;
            root->L = Z->L;
            root->R = Z->R;
        }*/
    }
    return returnVal;
}

node* AVLtree::s_rotate_L(node* Z) {
    node* k1, * k2;
    k2 = Z;
    k1 = Z->L;
    k2->L = k1->R;                          ///////////////////////////////////////////
    k1->R = k2;
    Z = k1;
    k1->height = max(nodeHeight((k2)->R), nodeHeight((k2)->L));
    k2->height = max(nodeHeight((k2)->R), nodeHeight((k2)->L));
    return Z;
}

node* AVLtree::s_rotate_R(node* Z) {
    node* k1, * k2;

    k1 = Z;
    k2 = Z->R;
    k1->R = k2->L;
    k2->L = k1;
    Z = k2;

    k1->height = max(nodeHeight((k2)->R), nodeHeight((k2)->L));
    k2->height = max(nodeHeight((k2)->R), nodeHeight((k2)->L));
    return Z;
}

node* AVLtree::d_rotate_L(node* Z) {
    s_rotate_L(Z);
    s_rotate_R((Z->R));
    return Z;
}

node* AVLtree::d_rotate_R(node* Z) {
    s_rotate_L((Z->R));
    s_rotate_R(Z);
    return Z;
}



node* AVLtree::insert(node* Z,int D) {
    if (Z == NULL){
     Z = new node;
     Z->L = Z->R = NULL;
     Z->Data = D;
     Z->height = 0;
     return Z;
        }
    else if (D < Z->Data) {
        Z->L = insert(Z->L, D);
        (Z->L)->height = (Z->height)+1;
        if ((nodeHeight(Z->L) - nodeHeight(Z)) == 2) { // I removed (Z->R) and it works for 
            if (D < Z->L->Data) {                       // insert, w/o balancing.
                s_rotate_L(Z);
            }
            else {
                d_rotate_L(Z);
            }
        }
        else {                                  // needs no balancing.
            Z->height = max(nodeHeight(Z->L), nodeHeight(Z->R) + 1);
        }
    }
    else if (D > Z->Data) {
        TempParent = Z;
        Z->R = insert(Z->R, D);
        (Z->R)->height = Z->height+1;           // points to child, neet Z=parent for rotation = ????????
        if ((nodeHeight(Z->R) - nodeHeight(Z->L)) == 2) {
            if (Z->R->Data < D) {
                s_rotate_R(Z);
            }
            else {
                d_rotate_R(Z);
            }
        }
        else {
            Z->height = max(nodeHeight(Z->L), nodeHeight(Z->R)) + 1;
        }
    }
    else {
        // data already in tree.
        // for HW2, add line# to link list.
        //
        //Data will be the LinkList.
    }
    return Z;
}

void AVLtree::displayTree(node* Z)
{
    if (Z != NULL) {
        //printf("%d", Z->Data);
        displayTree(Z->L);
        displayTree(Z->R);
        cout << Z->Data << " ";
    }
}

AVLtree::AVLtree()
{
    node* T;
    T = NULL;
    root = NULL;

}













