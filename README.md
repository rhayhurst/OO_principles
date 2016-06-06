# Object_Oriented_Linked_List

Author
---------------------------------------------------------------------
Bob Hayhurst
rhayhu2@uic.edu 
668 587 647
UIC, Fall 2016

Please give me an email if you have any problems with this project.
It should work like a charm.


Note to Venkat:

What if my test text file won't open?
-------------------------------------------------------------------------
If you want to run a text file with commands in it, feel free, the
functionality is there.  If you include a file in the project folder
and run the program, it will prompt you.

If the file doesn't open for some reason, please simply put a qualiied
path into the "open" command in line 125.

Instead of:

            inputFile.open(filename.c_str());

Put:

            inputFile.open("<qualified path\\filename.txt");


Note that the commands have spaces in between, and the text file
needs a return character after each command.




What is this program?
------------------------------------------------------------------------
It's for Professor Troy's CS 474 class, Object Oriented Programming
It was written in C++, developed in CLion IDE, Windows 10 OS




What does it do?
-------------------------------------------------------------------------
It allows you to create different types of linked lists and put integers
into the nodes.  The program explains itself fairly well.
Essentially, it forces the student to use inheritance and an abstract
class.





How do I run it?
--------------------------------------------------------------------------
There is a makefile bundled with the rest of the files.  If you're reading
this, then you've managed to unzip the files.

I have a Windows machine and I use mingw, so the make command that I use is
"mingw32-make.exe", but your Linux make should work, too.






Anything else I should know?
---------------------------------------------------------------------------
I used a command to clear the input buffer that supposedly only works on a
Windows machine: 

         fflush(stdin); // in the func "getUserCommand()"

If you have problems with the buffer, I apologize. If you run the program on
a Windows machine, I promise it will work.  If you don't have access to one,
give me an email, and I'll come demonstrate the program to you live and in 
person.


