#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node();
        virtual ~Node();

    int data;
    int weight;
    Node *next;


};

#endif // NODE_H
