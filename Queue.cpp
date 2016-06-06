#include "Queue.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Queue::Queue()
{
    head = NULL;
    tail = NULL;
    curr = NULL;
}

//---------- INHERITED METHODS -------------//
void Queue::insertIntoList(int v)
{
    //
    // create the node
    //
    nodePtr newNode = new Node;
    newNode->val = v;
    newNode->next = NULL;

    //
    // check if this is the first one.  If so, it's easy
    //
    if (NULL == tail)
    {
        tail = newNode;
        head = newNode;
        return;
    }

    //
    // else we gotta walk to the end of the line and insert there.
    //
    curr = head;
    while (NULL != curr)
    {
        if (NULL == curr->next)
        {
            tail = newNode;
            curr->next = tail;
            return;
        }
        curr = curr->next;
    }

    //
    // if we get here, then we've failed a sanity check
    //
    cout << "FAILED SANITY CHECK IN QUEUE INSERT" << endl;
    exit(EXIT_FAILURE);
}

void Queue::printList()
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
    cout << "list type: queue" << endl;
}

void Queue::removeValueFromList()
{
    //
    // check that it's not an initialized list that hasn't got a
    // node created in it yet
    //
    if (head == NULL)
    {
        cout << "Although this queue HAS been created, there are no values " << endl;
        cout << "in it.  Therefore, there is nothing to remove." << endl;
        return;
    }
    //
    // there MUST be an existing list if we get to this
    // part of the code.  Therefore, all we need to do is pop.
    //
    if (head->next == NULL)
    {
        cout << "Popping the only node from the stack, leaving an empty stack." << endl;
        cout << "The value in the node was '" << head->val << "'." << endl;
        head = NULL;
        return;
    }
    cout << "Deleting the value '" << head->val << "' from the stack." << endl;
    nodePtr deleteNode = new Node;
    deleteNode = head;
    head = head->next;
    delete(deleteNode);
}

int Queue::getValueFromList()
{
    int val = -999;
    if (NULL == head)
    {
        cout << "Although this queue HAS been created, there are no values " << endl;
        cout << "in it.  Therefore, there is nothing to 'get'." << endl;
        return val;
    }
    curr = head;
    while (curr != NULL)
    {
        if (NULL == curr->next)
        {
            val = curr->val;
            cout << "The integer '" << val << "' is at the front of the queue." << endl;
            return val;
        }
        curr = curr->next;
    }
}

//---------- END INHERITED METHODS -------------//

int Queue::countList()
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
