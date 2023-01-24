#include "deque.h"
#include<iostream>
using namespace std;



My_Deque::My_Deque()
{
    first = last = nullptr;
    size =0;
}

My_Deque::~My_Deque(){
    My_Deque::clear();
}

bool My_Deque::is_empty(){
    return(first==nullptr);
}

void My_Deque::push_back(int element)
{
    if(is_empty()){
        Node* newNode = new Node(element);
        first = last = newNode;
    }
    else{
        Node* newNode= new Node();
        newNode -> data = element;
        newNode -> next = nullptr;
        newNode -> prev = last ;
        last -> next = newNode;
        last = newNode;
    }
    size++;
}

void My_Deque::push_front(int element)
{
    if(is_empty()){
        Node* newNode = new Node(element);
        first = last = newNode;
    }
    else{
        Node* newNode= new Node();
        newNode -> data = element;
        newNode -> prev = nullptr;
        newNode -> next = first ;
        first -> prev = newNode;
        first = newNode;
    }
    size++;
}

int My_Deque::end()
{
    if(is_empty()) return -1;
    return last->data ;
}

int My_Deque::begin()
{
    if(is_empty()) return -1;
    return first->data;
}

int My_Deque::pop_back()
{
    int removed;
    if(is_empty())
        return -1;

    else if (size == 1 ){
        removed = first -> data ;
        delete first ;
        first = last = nullptr;
    }
    else{
        Node* temp = last;
        last = last -> prev;
        last -> next = nullptr;
        removed = temp -> data;
        delete temp;
    }
    size--;
    return removed;
}

int My_Deque::pop_front()
{
    int removed;
    if(is_empty())
        return -1;
    else if (size == 1 ){
        removed =  first -> data;
        delete first ;
        first = last = nullptr;
    }
    else{
        Node* temp = first;
        first = first -> next;
        first -> prev = nullptr;
        removed = temp -> data;
        delete temp;
    }
    size--;
    return removed;
}

void My_Deque::print()
{
    Node* temp = first;
    while(temp != nullptr){
        cout<<temp<<" ";
        temp = temp->next;
    }
}

void My_Deque::clear()
{
    while (first != last){
        Node* temp = first;
        first = first-> next;
        delete temp;
    }
    delete first ;
    first = last = nullptr ;
    size = 0 ;
}

int My_Deque::get_size()
{
    return size ;
}

std::vector<int> My_Deque::toVector()
{
    vector<int> v;
    Node* temp = first;
    while(temp != nullptr){
        v.push_back(temp->data);
        temp = temp -> next;
    }
    return v;
}