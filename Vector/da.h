#ifndef __DA_H__
#define __DA_H__

class My_DA{
    private:
        int size = 0;
        int capacity = 1;
        int* data = nullptr;
        
    public:
        My_DA();

        // Constructor that takes an array and its size ,so it is added directly to data
        My_DA(int[], int size);

        ~My_DA();
        
        // return the element at given index
        int get(int index);
        
        void push(int element);
        
        // remove the last element, return the removed element
        int pop();

        void insert(int index, int element);

        // remove the element at a given index, return the removed element
        int remove(int index);
        
        // print the whole array
        void print();

        // clear the whole array
        void clear();

        // given an element, return the first index of the given element if found, return -1 if not found
        int find(int);

        int get_size();
        
        int get_capacity();

        void shrink_to_fit();
};

#endif