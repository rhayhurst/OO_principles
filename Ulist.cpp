//
// Created by students on 2/28/2016.
//

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Ulist.h"
using namespace std;

// constructor
Ulist::Ulist()
{
    head = NULL;
    curr = NULL;
    temp = NULL;
}

//---------- INHERITED METHODS -------------//
void Ulist::insertIntoList(int v)
{
    // create the node
    nodePtr newNode = new Node;

    // set the node's pointer equal to the head of the list
    newNode->next = NULL;
    newNode->val = v;

    // set the list's head's next pointer equal to the new node, and likewise
    newNode->next = head;
    head = newNode;
}

void Ulist::removeValueFromList()
{
    //
    // check that it's not an initialized list that hasn't got a
    // node created in it yet
    //
    if (head == NULL)
    {
        cout << "Although this unordered list has been created, there are" << endl;
        cout << "no values in it.  Therefore, there is nothing to remove." << endl;
        return;
    }
    bool valueIsInList = false;

    //
    // get the value to be removed from the list
    //
    int v = getPositionToRemove();
    nodePtr deletePtr = NULL;
    temp = head;
    curr = head;

    //
    // Have curr walk throught the list, with temp right behind.
    // If we never come across the value, then it's not in the list.
    // Else, we delete it.
    //
    while (NULL != curr && v != curr->val)
    {
        temp = curr;
        curr = curr->next;
    }

    if (NULL == curr)
    {
        cout << "'" << v << "' is not in the list." << endl;
        cout << "To print the unordered list, use the command \"l <listNum>\"." << endl;
        delete (deletePtr);
    }
    else
    {
        deletePtr = curr;
        curr = curr->next;
        temp->next = curr;

        // deleting the front of the list is a special case
        if (deletePtr == head)
        {
            head = head->next;
            temp = NULL;
        }
        delete (deletePtr);
    }
}

void Ulist::printList()
{
    int i = countList();
    cout << "Number of nodes: " << i << endl;
    curr = head;
    i = 1;
    while (NULL != curr)
    {
        cout << "\t(" << i++ << ")\t " << curr->val << endl;
        curr = curr->next;
    }
    cout << "list type: unordered" << endl;
}

int Ulist::getValueFromList()
{
    int pos = getPosition();
    curr = head;
    int position = 1;
    while (NULL != curr)
    {
        if (position == pos) break;
        curr = curr->next;
        position++;
    }

    if (NULL == curr) // then the position is not in the list
    {
        cout << "There has been no node created at position '" << pos << "'." << endl;
        cout << "To print the unordered list, use the command \"l <listNum>\"." << endl;
        return -999;
    }
    else
    {
        cout << "The integer '" << curr->val << "' is in position '" << pos << "'." << endl;
        return curr->val;
    }
}
//-------- END INHERITED METHODS-----------//
int Ulist::countList()
{
    int i = 0;
    curr = head;
    while (NULL != curr)
    {
        curr = curr->next;
        i++;
    }
    return i;
}

int Ulist::getPositionToRemove()
{
    char _pos[81];
    int pos;
    cout << "Please enter the value that you would" << endl;
    cout << "to remove from the unordered list." << endl;
    bool isInt = false;
    int numFails = 0;
    while (!isInt)
    {
        cout << "->: ";
        cin.getline(_pos, 81);
        if(!argIsNotDigits(_pos))
        {
            switch(numFails)
            {
                case(0):
                    cout << "Um, we need an integer here.  Try that again?" << endl;
                    break;
                case(1):
                    cout << "Didn't we just go through this?  A position... needs an integer." << endl;
                    break;
                case(2):
                    cout << "Didn't we just go through this?  A POSITION NUMBER needs a NUMBER." << endl;
                    break;
                default:
                    cout << "THAT'S IT!  I QUIT!" << endl;
                    exit(EXIT_FAILURE);
            }
            numFails++;
        }
        else
        {
            pos = atoi(_pos);
            isInt = true;
        }
    }
    return pos;
}

int Ulist::getPosition()
{
    int pos;
    cout << "What node would you like the value of?" << endl;
    cout << "(nodes start at position '1')" << endl;
    cout << "->: ";
    cin >> pos;
    return pos;
}

bool Ulist::argIsNotDigits(char *pos)
{
    for (int i = 0; i < strlen(pos); i++)
    {
        if (!isdigit(pos[i]))
        {
            cout << "This argument must be a number." << endl;
            cout << "It has the character '" << pos[i] << "'." << endl;
            return false;
        }
    }
    return true;
}
