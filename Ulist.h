

#ifndef INHERITANCE_RHAYHU2_ULIST_H
#define INHERITANCE_RHAYHU2_ULIST_H


#include "List.h"

class Ulist : public List
{
private:
    typedef struct Node
    {
        int val;
        Node * next;
    }*nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr temp;


public:
    Ulist();
    //---------- INHERITED METHODS -------------//
    void insertIntoList(int);
    void printList();
    void removeValueFromList();
    int getValueFromList();
    //-------- END INHERITED METHODS-----------//
    int countList();
    int getPositionToRemove();
    int getPosition();
    bool argIsNotDigits(char pos[81]);
};


#endif //INHERITANCE_RHAYHU2_ULIST_H
