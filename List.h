//
// Created by students on 2/28/2016.
//

#ifndef INHERITANCE_RHAYHU2_LIST_H
#define INHERITANCE_RHAYHU2_LIST_H


class List
{
public:
    virtual void insertIntoList(int) = 0;
    virtual void printList() = 0;
    virtual void removeValueFromList() = 0;
    virtual int getValueFromList() = 0;
};


#endif //INHERITANCE_RHAYHU2_LIST_H
