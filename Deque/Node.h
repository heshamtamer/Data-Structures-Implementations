#ifndef __Node_H__
#define __Node_H__
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
    Node(){
        next = nullptr;
        prev = nullptr;
    }

    Node(int element){
        next = nullptr;
        prev = nullptr;
        data = element;
    }
};
#endif