//
// Created by students on 2/29/2016.
//

#ifndef INHERITANCE_RHAYHU2_QUEUE_H
#define INHERITANCE_RHAYHU2_QUEUE_H
#include "List.h"

class Queue : public List
{
private:
    typedef struct Node
    {
        int val;
        Node * next;
    }*nodePtr;

    nodePtr head;
    nodePtr tail;
    nodePtr curr;

public:
    Queue();
    //---------- INHERITED METHODS -------------//
    void insertIntoList(int);
    void printList();
    void removeValueFromList();
    int getValueFromList();
    //-------- END INHERITED METHODS-----------//
    int countList();
};


#endif //INHERITANCE_RHAYHU2_QUEUE_H
