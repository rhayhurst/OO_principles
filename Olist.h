//
// Created by students on 2/28/2016.
//

#ifndef INHERITANCE_RHAYHU2_OLIST_H
#define INHERITANCE_RHAYHU2_OLIST_H


#include "List.h"

class Olist : public List
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
    Olist();
    //---------- INHERITED METHODS -------------//
    void insertIntoList(int);
    void printList();
    void removeValueFromList();
    int getValueFromList();
    //-------- END INHERITED METHODS-----------//

    int countList();

    int getPositionToRemove();

    bool argIsNotDigits(char pos[81]);

    int getPosition();
};


#endif //INHERITANCE_RHAYHU2_OLIST_H
