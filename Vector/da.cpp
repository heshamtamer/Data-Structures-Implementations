#include "da.h"
#include<iostream>
using namespace std;
My_DA::My_DA()
{
   size=0; capacity=1;   data = new int[capacity];
}
My_DA::My_DA(int arr[], int n)
{
    size=0; capacity=1;
      for(int i=0;i<n;i++) {
         size++;
         if(size==capacity) capacity=capacity*2;
      }
    data = new int[capacity];
    for(int i=0; i<n; i++)
    {
        data[i]=arr[i];
    }
}

My_DA::~My_DA()
{
    if(data !=NULL)
        delete[] data;
}
void My_DA::push(int element)
{
    if(size<capacity) {
        data[size] = element;
        size++;
    }
    else
    {
        capacity *=2;
        int *old_data =data;
        data = new int[capacity];
        for(int i=0; i<size; i++)
        {
            data[i]=old_data[i];
        }
        delete [] old_data;
        data[size] = element;
        size++;
    }
}

int My_DA::pop()
{
    int val =data[size-1];
    if(!size)
        return -1;
    size--;
    if(size<capacity/2) {
        capacity /= 2;
        int *old_data =data;
        data = new int[capacity];
        for(int i=0; i<size; i++)
        {
            data[i]=old_data[i];
        }
        delete [] old_data;
    }
    return val;
}
int My_DA::find(int value)
{
    for(int i=0; i<size; i++)
    {
        if(data[i] == value)
            return i;
    }
    return -1;
}

int My_DA::get_capacity()
{
    return capacity;
}

int My_DA::get_size()
{
    return size;
}

void My_DA::print()
{
    for(int i=0; i<size; i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

int My_DA::get(int index)
{
   if(index<size) return data[index];
    return -1;
}

void My_DA::shrink_to_fit()
{
    int *arr = new int[size]; capacity = size;
    for(int i=0; i<size; i++)
    {
        arr[i] = data[i];
    }
    delete []data; data = arr;
}

void My_DA::clear()
{
    delete []data; size=0; capacity=1;
    data=new int[capacity];
}
void My_DA::insert(int index, int element)
{
    if(size<capacity){
        for(int i=size;i>index;i--){
            data[i]=data[i-1];
        }
        data[index]=element;
        size++;
    }
    else{
        capacity *=2;
        int *old_data =data;
        data = new int[capacity];
        for(int i=0; i<size; i++)
        {
            data[i]=old_data[i];
        }
        delete [] old_data;
        for(int i=size;i>=index;i--){
            data[i]=data[i-1];
        }
        data[index]=element;
        size++;
    }
}

int My_DA::remove(int index)
{
    if(index>=size) return -1;
    int val = data [index];
    for(int i=index;i<size-1;i++)
    {
       data[i]=data[i+1];
    }
    size--;
    if(size<capacity/2) {
        capacity /= 2;
        int *old_data =data;
        data = new int[capacity];
        for(int i=0; i<size; i++)
        {
            data[i]=old_data[i];
        }
        delete [] old_data;
    }
    return val;
}

// implement all the methods in da.h
// feel free to add new helper methods whether private or public