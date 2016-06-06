

#include "Stack.h"
#include <iostream>
using namespace std;

// constructor
Stack::Stack()
{
    stackPointer = NULL;
    curr = NULL;
}
//---------- INHERITED METHODS -------------//
void Stack::insertIntoList(int v)
{
    //
    // create the new node, put the value in it
    //
    nodePtr newNode = new Node;
    newNode->val = v;

    //
    // if it's the first node in the list
    //
    if (NULL == stackPointer)
    {
        newNode->next = NULL;
        stackPointer = newNode;
        return;
    }

    //
    // else it's not, and we just push it on
    //
    newNode->next = stackPointer;
    stackPointer = newNode;
}

void Stack::printList()
{
    int i = countList();
    cout << "Number of nodes: " << i << endl;
    curr = stackPointer;
    i = 1;
    while (NULL != curr)
    {
        cout << "\t(" << i++ << ")\t " << curr->val << endl;
        curr = curr->next;
    }
    cout << "list type: stack" << endl;
}

void Stack::removeValueFromList()
{
    //
    // check that it's not an initialized list that hasn't got a
    // node created in it yet
    //
    if (stackPointer == NULL)
    {
        cout << "Although this stack HAS been created, there are no values " << endl;
        cout << "in it.  Therefore, there is nothing to remove." << endl;
        return;
    }
    //
    // there MUST be an existing list if we get to this
    // part of the code.  Therefore, all we need to do is pop.
    //
    if (stackPointer->next == NULL)
    {
        cout << "Popping the only node from the stack, leaving an empty stack." << endl;
        cout << "The value in the node was '" << stackPointer->val << "'." << endl;
        stackPointer = NULL;
        return;
    }
    cout << "Deleting the value '" << stackPointer->val << "' from the stack." << endl;
    nodePtr deleteNode = new Node;
    deleteNode = stackPointer;
    stackPointer = stackPointer->next;
    delete(deleteNode);
}

int Stack::getValueFromList()
{
    //
    // check that it's not an initialized list that hasn't got a
    // node created in it yet
    //
    if (stackPointer == NULL)
    {
        cout << "Although this stack HAS been created, there are no values " << endl;
        cout << "in it.  Therefore, there is nothing to 'get'." << endl;
        return -999;
    }

    int value = stackPointer->val;
    cout << "The integer '" << value << "' is on top of the stack." << endl;
    return value;

}
//---------- END INHERITED METHODS -------------//

int Stack::countList()
{
    int i = 0;
    curr = stackPointer;
    while (NULL != curr)
    {
        curr = curr->next;
        i++;
    }
    return i;
}
