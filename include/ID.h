#ifndef ID_H
#define ID_H
#include "Node.h"
#include <queue>

class ID
{
    public:
        ID();
        virtual ~ID();
        void add_node_to_list(int d,int w);
        void delete_node_from_list(int d);
        void sort_list();

    int element;
   Node *list_head;



};

#endif // ID_H
