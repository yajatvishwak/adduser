# adduser
PES programs - 2020 Quarantine and chill

------------------Guidelines which i obviously wont follow lmao-------------------
GUIDELINES TO FOLLOW WHILE WRITING CODE
1. Make sure that you have your code in at least 2 .c files and one .h file.
2. You need to have a relevant makefile to build the executable.
3. Accept as many inputs as possible through command line arguments
4. The “main” function should be restricted to just taking the required inputs, calling other
functions for the required processing and then displaying the results
5. Avoid (minimize) the use of global variables (If you are using, you have to justify why you
have to use global variables – apart from saying “it makes your life easier”)
6. The functions as far as possible, have to accept arguments and return the required
result. If you have functions which do not accept any parameters and do not return
anything, that code might as well be part of the main function.
7. When you build the executable, make sure that there are no “warnings” left.
8. The variables used in your program should have meaningful names. Avoid using i,j,k,l,
.....
9. Write meaningful comments. A program without comments will not be accepted
10. Check for all possible error conditions and handle these gracefully.
11. Validate all the input values
12. Clearly mention any known bugs still left in the program which you are unable to fix.
13. Clearly mention any assumptions you have made
14. Also, mention any constraints under which your program might work correctly.
15. GUI is not mandatory.
16. It would be good to make sure all these programs work on Windows as well as Linux.


------------------Program Statment--------------------

Write a program in C to mimic the “adduser” command on Linux. This command will add either an ordinary user or a system user. It has to handle 2 files “passwd” and “shadow”. Both these files will be in some folder specified by an environment variable PFILE. The program has to take all arguments as command line arguments (Refer man pages for the command line arguments)
When we run ‘adduser‘ command in Linux terminal, it performs following major things:
It edits /etc/passwd, /etc/shadow, /etc/group and /etc/gshadow files for the newly created User account.
Creates and populate a home directory for the new user.
Sets permissions and ownerships to home directory.


To run the file,
```
pray to god, he is the answer
```
alright alright..jeez calm down
```
gcc -Wall -c server.c    
```
```
gcc -Wall -c adduser.c    
```
```
gcc -o xaea12 server.o adduser.o
```

To add a user,
```
./xaea12 -u 1000 -g 1000 -c "big chungus" bettlejuice
```
- Then put whatever password you want
- Then show the passwd and shadow file to your teacher to get full marks lmao

