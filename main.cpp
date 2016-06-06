
           /**************************
            ***    Bob Hayhurst   ***
            *** rhayhu2, 668587647***
            *** Project 2, CS 474 ***
            ***   Fall 2016, UIC  ***
            *************************/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include "List.h"
#include "Ulist.h"
#include "Olist.h"
#include "Stack.h"
#include "Queue.h"
#define FAIL_SANITY_CHECK 1
#define NUMLISTS 8
using namespace std;

//
// a few globals
//
const int size        = 20;   // max number of characeters in each file command
const int maxNumWords = 200;  // max number of command in file
const int mSecs       = 500; // for pause

//
// local functions
//
void welcome();
void hint();
void getUserCommand(char*);
void resetVariables(char&,char&,int&,int&);
bool validateInput(char*,char&,int&,int&,char&);
int getNumberOfArguments(char*);
bool argumentDoesNotConsistOfAllDigits(char*);
bool firstArgIsSingleCharacter(char*);
bool argumentIsNotBetween1And8(int);
bool argIsNotOfTypeList(char*);
bool isCommandNullInput(char *input);
void help();
void about();
void exitProgram(int);
bool quit();
void setListNumber(int,char,List**);
void printNoListMessage();
void insertValueIntoList(int,int,List**);
void removeValueFromList(int,int,List**);
void printTheList(int,List**);
void getValueFromList(int,List**);
void checkForRecursiveFileCommand(char[maxNumWords][size],int);
void endOfFile();
void printSetList(int number, char type);
void ellipse();
void printInsertStatement(int,int);
void printRemoveStatement(int);
void printGetValue(int);
string getFilename();

void pause(unsigned secs = 1U)
{
   clock_t wait = secs+mSecs+clock();
   while(wait > clock()) continue;
}

int main()
{
    ifstream inputFile;
    // create the array of Base class
    List* lists[NUMLISTS];
    for (int i = 0; i < NUMLISTS; i++) lists[i] = 0;

    char userCommand;
    char listType;
    int listNumber;
    int value;
    char input[81];

    //
    // variables for reading in the file
    //
    string filename;
    bool readInFile = false;
    bool gotCommandsFromFile = false;
    int commandIterator = 0;
    int numCommands = 0;
    char commands[maxNumWords][size];
    welcome();

    //
    // loop that allows the user to enter commands.
    //
    bool loop = true;
    while (loop)
    {
        //
        // if we need to get the commands from a text file, this is where we do it
        //
        if (readInFile && !gotCommandsFromFile)
        {
            gotCommandsFromFile = true;


            //
            // open the file
            //
            // NOTE:
            //
            // This WILL work with qualified path.
            // It does NOT work without a qualified path.  I've tried every variations that there is:  switching to std::C++11, using "c_str()", anything 
            // that I could find.
            // Just note that if it doensn't work, put in a qualified path to the text file.
            // I've include a test file in the project called "command.txt"
            //
            //inputFile.open("C:\\Users\\students\\Dropbox\\CURR_Spring_2016\\object_oriented_programming\\projects\\proj2_inheritance\\bhayhu2_proj2\\commandFile.txt");
            //
            //
            // Opps!  I was surrounding my filename with quotes.  Thought that was needed....
            //
            //
            inputFile.open(filename.c_str());
            if (inputFile.fail())
            {
                cout << "Error opening file.  Please read the README and comments on line 111 for extra information!!" << endl;
                exit(EXIT_FAILURE);
            }

            //
            // read the commands into the array of commands
            //
            string s;
            while (getline(inputFile,s))
            {
                char *w = new char[s.length()+1];
                strcpy(commands[numCommands++], s.c_str());
            }

            //
            // make sure there's no "f" in the input file
            //
            checkForRecursiveFileCommand(commands, numCommands);
        }
        //
        // inner loop to check that the user command is valid
        //
        bool validInput = false;
        while (!validInput)
        {
            //
            // reset some of the variables (may not be necessary, but good practice)
            //
            resetVariables(userCommand, listType, listNumber, value);

            //
            // get the command, either from the user or from the file
            //
            if (!readInFile) getUserCommand(input);
            else if (commandIterator == numCommands) endOfFile();
            else strcpy(input, commands[commandIterator++]);

            //
            // see if the command is legit
            //
            if (!validateInput(input, userCommand, listNumber, value, listType)) hint();
            else validInput = true;
        }

        //
        // run the actual command
        //
        switch (userCommand)
        {
            case ('q'):
                if (quit()) loop = false;
                break;

            case ('h'):
                help();
                break;

            case ('a'):
                about();
                break;

            case ('s'):
                printSetList(listNumber, listType);
                setListNumber(listNumber-1, listType, lists);
                break;

            case('i'):
                printInsertStatement(listNumber,value);
                insertValueIntoList(listNumber-1, value, lists);
                break;

            case ('r'):
                printRemoveStatement(listNumber);
                removeValueFromList(listNumber-1, value, lists);
                break;

            case('l'):
                printTheList(listNumber-1, lists);
                break;

            case('g'):
                printGetValue(listNumber);
                getValueFromList(listNumber-1, lists);
                break;

            case('f'):
                readInFile = true;
                filename = getFilename();
                break;

            default:
                exitProgram(FAIL_SANITY_CHECK);

        }// end command switch case
    }// end while loop that runs until user quits
    cout << "Leaving program..";
    ellipse();
    return 0;
}

string getFilename()
{
    string filename;
    cout << "Please enter the name of the file (including its extension)." << endl;
    cout << "->: ";
    cin >> filename;
    //filename = "\"" + filename + "\"";
    return filename;
}

void checkForRecursiveFileCommand(char commands[maxNumWords][size], int numCommands)
{
    for (int i = 0; i < numCommands; i++)
        for (int j = 0; j < strlen(commands[i]); j++)
        {
            if ('f' == commands[i][j])
            {
                cout << "You have an 'f' command in your file." << endl;
                cout << "We're not equipped for that." << endl;
                cout << "Exiting program..." << endl;
                exit(EXIT_FAILURE);
            }
        }
}

void getValueFromList(int number, List *lists[8])
{
    //
    // make sure that the list has been inititalized
    //
    if (NULL == lists[number]) printNoListMessage();
    else
    {
        lists[number]->getValueFromList();
    }
}

void printTheList(int number, List *lists[8])
{
    //
    // make sure that the list has been inititalized
    //
    if (NULL == lists[number]) printNoListMessage();
    else
    {
        lists[number]->printList();
        pause();pause();pause();
    }
}

void removeValueFromList(int number, int value, List *lists[NUMLISTS])
{
    //
    // make sure that the list has been inititalized
    //
    if (NULL == lists[number])
    {
        printNoListMessage();
    }
    else
    {
        lists[number]->removeValueFromList();
    }
}

void insertValueIntoList(int number, int value, List *lists[NUMLISTS])
{
    // make sure that the list has been initialized
    if (NULL == lists[number])
        printNoListMessage();

    // is has been initialized, and we can run command
    else lists[number]->insertIntoList(value);
}

void setListNumber(int number, char type, List* lists[NUMLISTS])
{
    // first check if the list is empty, if it's not, delete it
    if (lists[number] != 0) lists[number] = NULL;

    // then add the type of list
    switch(type)
    {
        case('u'):
            lists[number] = new Ulist();
            break;
        case('o'):
            lists[number] = new Olist();
            break;
        case('s'):
            lists[number] = new Stack();
            break;
        case('q'):
            lists[number] = new Queue();
             break;
        default:
            exitProgram(FAIL_SANITY_CHECK);
    }
}

void resetVariables(char& command, char &type, int &number, int &value)
{
    command = 'X';
    type    = 'X';
    number  = -999;
    value   = -999;
}

/**
 * Checks that the user entered argument is ok.
 * The first character must be specific and the second two must be integers, unless "set" is command.
 * We can also assign the proper variables for the command functions here as well.
 */
bool validateInput(char input[81], char &command, int &listNumber, int &value, char& listType)
{
    //
    // right off the bat, check that there's actually a command
    //
    if (!isCommandNullInput(input)) return false;

    //
    // get the number of arguments in the command
    //
    int numArgs = getNumberOfArguments(input);

    //
    // walk through the command, validating input and assigning variables
    //
    int argNumber = 0;
    char* currArgument = strtok(input, " ");
    while (NULL != currArgument)
    {
        switch (argNumber)
        {
            case(0):
                if (!firstArgIsSingleCharacter(currArgument)) return false;
                else command = currArgument[0];
                if (1 == numArgs) return true;
                else break;

            case(1):
                //
                // lots of checks
                //
                if ('f' == command) return true;
                if (!argumentDoesNotConsistOfAllDigits(currArgument)) return false;
                if (!argumentIsNotBetween1And8(atoi(currArgument))) return false;
                listNumber = atoi(currArgument);
                if (2 == numArgs) return true;
                else break;

            case(2):
                // if the command is 's', then argument must be char of type "list"
                if ('s' == command)
                {
                    if (!argIsNotOfTypeList(currArgument)) return false;
                    else listType = currArgument[0];
                }

                    //
                    // else the user has entered the only other three arg command, "insert"
                    //
                else
                {
                    if (!argumentDoesNotConsistOfAllDigits(currArgument)) return false;
                    else value = atoi(currArgument);
                }

                if (3 == numArgs) return true;
                else break;

            default:
                cout << "Your command must have a maximum of three arguments." << endl;
                return false;
        }
        currArgument = strtok(NULL, " ");
        argNumber++;
    }
    return false;
}

void printNoListMessage()
{
    cout << "You haven't created this list yet.  To create a list," << endl;
    cout << "use the command: s <list number> <list type>." << endl;
    cout << "Try the command 'h' for a list of other commands." << endl;
}

bool isCommandNullInput(char *input)
{
    if (NULL == input)
    {
        cout << "You must put in at least one command." << endl;
        return false;
    }
    return true;
}

int getNumberOfArguments(char *input)
{
    int numArgs = 1;
    for (int i = 0; i < strlen(input); i++)
        if (' ' == input[i]) numArgs++;
    return numArgs;
}

bool argIsNotOfTypeList(char *arg)
{
    if (1 != strlen(arg))
    {
        cout << "Since you are setting a list type, you can only enter a single character." << endl;
        return false;
    }

    if (strcmp("u", arg) != 0 && strcmp("o", arg) != 0 &&
        strcmp("s", arg) != 0 && strcmp("q", arg) != 0)
    {
        cout << "List type must be:" << endl;
        cout << "'u': unordered list" << endl;
        cout << "'o': ordered list" << endl;
        cout << "'s': stack" << endl;
        cout << "'q': queue" << endl;
        return false;
    }
    return true;
}

bool argumentDoesNotConsistOfAllDigits(char *argument)
{
    for (int i = 0; i < strlen(argument); i++)
    {
        if (!isdigit(argument[i]))
        {
            cout << "This argument must be a number." << endl;
            cout << "It has the character '" << argument[i] << "'." << endl;
            return false;
        }
    }
    return true;
}

bool argumentIsNotBetween1And8(int n)
{
    if (0 >= n || n >= 9)
    {
        cout << "The list number must be between 1 and 8." << endl;
        cout << "You entered '" << n << "'." << endl;
        return false;
    }
    return true;
}

bool firstArgIsSingleCharacter(char *argument)
{
    if (1 != strlen(argument))
    {
        cout << "The first argument in your command must be a single letter." << endl;
        return false;
    }
    else // it IS only a single letter
    {
        if (strcmp("q", argument) != 0 && strcmp("h", argument) != 0 && strcmp("a", argument) != 0 &&
            strcmp("l", argument) != 0 && strcmp("r", argument) != 0 && strcmp("g", argument) != 0 &&
            strcmp("f", argument) != 0 && strcmp("s", argument) != 0 && strcmp("i", argument) != 0)
        {
            cout << "'" << argument << "' is not a valid command." << endl;
            return false;
        }
    }
    return true;
}

void getUserCommand(char input[81])
{
    fflush(stdin); // only works with windows OS
    cout << "->:  ";
    cin.getline(input, 81);
}

void welcome()
{
    cout << "\n\nHello!  This is a program that allows you to create various types of linked lists.\n" << endl;
    hint();
    cout << "\nPlease enter a command.\n" << endl;
}

void hint()
{
    cout << "Enter \"h\" for a list of commands,\n";
    cout << "Enter \"a\" for information about the author.\n";
}

void help()
{
    cout << "This program allows you to create and manage eight separate linked lists, of which " << endl;
    cout << "there are four types of lists.  The lists hold integers.  The types of lists are:\n" << endl;
    cout << "(1) unordered list: <type> = o  Integers will be placeed at the head of the list, in no specific order." << endl;
    cout << "(2) ordered list:   <type> = u  Integers will be placed in ascending order (small-to-large)." << endl;
    cout << "(3) queue:          <type> = q  Integers follow a \"first-in-first-out\" order.  Just like a regular queue" << endl;
    cout << "                                at, say, a bank." << endl;
    cout << "(4) stack:          <type> = s  Integers follow a \"last-in-first-out\" order.  Just like a regular line" << endl;
    cout << "                                at, say, the bank when you're in a hurry.\n" << endl;
    cout << "There are 9 commands you can make:\n" << endl;
    cout << "q\tquit the program" << endl;
    cout << "h\thelp" << endl;
    cout << "a\tabout the makers of this fine piece of technology" << endl;
    cout << "s <listNum> <type>\tInitialize a list to a specified type.  If that list already has values in it, those" <<endl;
    cout << "                        values will be deleted." <<endl;
    cout << "i <listNum> <int>\tInsert a value into a sepcific list.  See the description of the types of lists to" << endl;
    cout << "                        determine how the lists will behave." << endl;
    cout << "r <listNum>\tRemove a value from the list.  For the unordered and ordered list, you will be asked what" << endl;
    cout << "                value to remove from the list.  For the queue and stack, the first value in the list will" << endl;
    cout << "                will be removed." << endl;
    cout << "l <listNum>\tPrint information about this list." << endl;
    cout << "f <filename>\tThe filename will be a file located in the same project folder as the program itself." << endl;
    cout << "                It should contain commands themselves that will be run.\n\n" << endl;
}

void about()
{
    cout << "     \n\n*************************\n";
    cout << "     ***    Bob Hayhurst   ***\n";
    cout << "     *** rhayhu2, 668587647***\n";
    cout << "     *** Project 2, CS 474 ***\n";
    cout << "     ***   Fall 2016, UIC  ***\n";
    cout << "     *************************\n\n";
    cout << "\n\n(no nerds ";
    pause();pause();pause();
    cout << "were harmed in the creation of this program)\n\n\n" << endl;
}

void exitProgram(int i)
{
    if (i == FAIL_SANITY_CHECK)
    {
        cout << "Failed sanity check." << endl;
        cout << "Exiting program with failure code..." << endl;
        exit(EXIT_FAILURE);
    }
}

bool quit()
{
    char c;
    cout << "Are you sure you want to quit?" << endl;
    cout << "Enter 'y' if you're sure." << endl;
    cout << "->:  ";
    cin >> c;
    if ('y' == c || 'Y' == c) return true;
    return false;
}

void endOfFile()
{
    cout << "That's the end of your file." << endl;
    exit(EXIT_SUCCESS);
}

void printSetList(int number, char type)
{
    cout << "Creating list in space '" << number << "' of type ";
    if      ('u' == type) cout << "unordered list";
    else if ('o' == type) cout << "ordered list";
    else if ('s' == type) cout << "stack";
    else                  cout << "queue";
    ellipse();
}

void printInsertStatement(int number, int value)
{
    cout << "Inserting '" << value << "' into list number '" << number <<"'";
    ellipse();
}

void printRemoveStatement(int number)
{
    cout << "Removing from list number '" << number << "'";
    ellipse();
}

void printGetValue(int number)
{
    cout << "Getting value from list number '" << number << "'";
    ellipse();
}

void ellipse()
{
    cout << ".";
    pause();
    cout << ".";
    pause();
    cout << "." << endl;
}





