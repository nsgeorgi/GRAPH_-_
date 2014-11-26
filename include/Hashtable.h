#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "ID.h"

class Hashtable
{
    public:
        Hashtable(int s);
        virtual ~Hashtable();
        void insert_all_data(char s[]);
        void insert(int key,int key2,int key3);
        void delete_(int key,int key2);
        int prim();
        int merging(int key,int key2);
        int  search(int k);
        struct N
    {
        int value;
        int w;
        bool operator<(const  N& n2) const {
        return w>n2.w;}
    };


    private:
    int size; //megethos hashtable
    ID *ht;   //hash table array
    bool *empty; //1D array
};

#endif // HASHTABLE_H
