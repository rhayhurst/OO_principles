#ifndef INHERITANCE_RHAYHU2_STACK_H
#define INHERITANCE_RHAYHU2_STACK_H
#include "List.h"

class Stack : public List
{
private:
    typedef struct Node
    {
        int val;
        Node * next;
    }*nodePtr;

    nodePtr stackPointer;
    nodePtr curr;
public:
    Stack();
    //---------- INHERITED METHODS -------------//
    void insertIntoList(int);
    void printList();
    void removeValueFromList();
    int getValueFromList();
    //-------- END INHERITED METHODS-----------//
    int countList();
};


#endif //INHERITANCE_RHAYHU2_STACK_H
