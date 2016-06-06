
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Olist.h"
using namespace std;

Olist::Olist()
{
    head = NULL;
    curr = NULL;
    temp = NULL;
}

//---------- INHERITED METHODS -------------//
void Olist::insertIntoList(int v)
{
    // create the node, insert the value
    nodePtr newNode = new Node;
    newNode->next = NULL;
    newNode->val = v;

    //
    // check if this is the first node in the series
    // if so, then we're good!
    //
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    //
    // then, check if the node needs to go at the front of the list
    // or this is the first node in the list
    //
    if (head->val >= newNode->val)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    //
    // if we get here, then we need to insert the val in ascending order
    //
    temp = head;
    curr = head;
    while (curr->next != NULL)
    {
        if (curr->val > newNode->val && temp->val <= newNode->val)
        {
            temp->next = newNode;
            newNode->next = curr;
            return;
        }
        temp = curr;
        curr = curr->next;
    }

    // and if we get here, curr is at the end, and the node needs to go at the end
    curr->next = newNode;
}

void Olist::printList()
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
    cout << "list type: ordered (ascending order)" << endl;
}

void Olist::removeValueFromList()
{
    //
    // check that it's not an initialized list that hasn't got a
    // node created in it yet
    //
    if (head == NULL)
    {
        cout << "Although this ordered list HAS been created, there are" << endl;
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
    //
    while (NULL != curr && v != curr->val)
    {
        temp = curr;
        curr = curr->next;
    }

    if (NULL == curr)
    {
        cout << "'" << v << "' is not in the list." << endl;
        cout << "To see the ordered list, use the command \"l <listNum>\"." << endl;
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

int Olist::getValueFromList()
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
        cout << "To print the ordered list, use the command \"l <listNum>\"." << endl;
        return -999;
    }
    else
    {
        cout << "The integer '" << curr->val << "' is in position '" << pos << "'." << endl;
        return curr->val;
    }
}

//-------- END INHERITED METHODS -----------//
int Olist::countList()
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

int Olist::getPositionToRemove()
{
    char _pos[81];
    int pos;
    cout << "Please enter the value that you would" << endl;
    cout << "to remove from the unordered list." << endl;
    bool isInt = false;
    while (!isInt)
    {
        cout << "->: ";
        cin.getline(_pos, 81);
        if(!argIsNotDigits(_pos))
        {
            cout << "Um, we need an integer here.  Try that again?" << endl;
        }
        else
        {
            pos = atoi(_pos);
            isInt = true;
        }
    }
    return pos;
}

bool Olist::argIsNotDigits(char *pos)
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

int Olist::getPosition()
{
    int pos;
    cout << "What node would you like the value of?" << endl;
    cout << "(nodes start at position '1')" << endl;
    cout << "->: ";
    cin >> pos;
    return pos;
}
