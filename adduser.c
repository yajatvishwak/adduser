#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *getfield(char *line, int num) // Traversing or Tokenizing a ':' seperated String
{
    char *tok;
    for (tok = strtok(line, ":");
         tok && *tok;
         tok = strtok(NULL, ":\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int str2int(char *s) // String -> number converter
{
    int i, n;
    for (n = 0, i = 0; s[i] != '\0'; i++)
        n = n * 10 + (s[i] - '0');
    return n;
}
char *concat(const char *s1, const char *s2) // UDF to concat because whynot?
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1);
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1);
    return result;
}

int main(int argc, char **argv)
{
    // Arrays and variables Declaration
    int i = 0;                                                                                           // Loop variable
    int USERIDS[100];                                                                                    // MAX amount of users that can be stored
    int uid, gid;                                                                                        // Unique id and Group id of the user
    char comment[100];                                                                                   // extra comments that the user wants to store
    char line[1024];                                                                                     // Used for parsing file line by line
    char pass[100];                                                                                      // Password of the user
    char fpass;                                                                                          // Password checking character, is x if password is present null if not
    char user[100];                                                                                      // the name of the user
    int isPresent = 0;                                                                                   // variable to check if the user is already present
    char *floc;                                                                                          // To store the env pfile variable
    putenv("PFILE=/media/yajat-vishwakk/MainHDD/Coding/college-programs-and-projects/pes-prog/adduser"); //enter your env variable here
    assert((floc = getenv("PFILE")) != NULL);                                                            // setting floc to env variable

    FILE *passwdPTR;                                  // File Pointer to write in file in append mode
    passwdPTR = fopen(concat(floc, "/passwd"), "a+"); // concating the location of the file and opening it
    FILE *RpasswdPTR;                                 // file pointer to read into the file
    RpasswdPTR = fopen(concat(floc, "/passwd"), "r"); // concating the location of the file and opening it
    FILE *shadowPTR;                                  // file pointer to read into the file
    shadowPTR = fopen(concat(floc, "/shadow"), "a+"); // concating the location of the file and opening it

    // Step 1. segregate the inputs, i. divide the parameters

    for (i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-u") == 0)
        {
            uid = atoi(argv[i + 1]);
        }
        else if (strcmp(argv[i], "-g") == 0)
        {
            gid = atoi(argv[i + 1]);
        }
        else if (strcmp(argv[i], "-c") == 0)
        {
            strcpy(comment, argv[i + 1]);
        }
        if (i == argc - 1)
        {
            strcpy(user, argv[i]);
        }
    }

    // Step2. Take in the password of the new user
    printf("Creating User... \n");
    printf("Enter password : ");
    scanf(" %s", pass);

    if (strlen(pass) != 0)
    {
        fpass = 'x';
    }
    else
    {
        fpass = ' ';
    }

    // initialising array to be zero thats why Uid can not be zero
    for (i = 0; i < 100; i++)
    {
        USERIDS[i] = 0;
    }

    i = 0;
    //Storing the previous users in file in a buffer
    while (fgets(line, 1024, RpasswdPTR))
    {
        char *tmp = strdup(line);
        USERIDS[i] = str2int(getfield(tmp, 3));
        free(tmp);
    }
    //checking if user is present or not
    for (i = 0; i < 100; i++)
    {
        if (USERIDS[i] == uid)
        {
            isPresent = 1;
        }
    }
    //IF NOT PRESENT ADD
    if (isPresent == 1 || uid == 0)
    {
        printf("Specified UID Taken. Please choose another UID");
    }
    else
    {
        fprintf(passwdPTR, "%s:%c:%d:%d:%s:/user/home:/user/home\n", user, fpass, uid, gid, comment);
        fprintf(shadowPTR, "%s:%s:%d\n", user, pass, uid);
        fclose(passwdPTR);
        fclose(shadowPTR);
    }
    return 0;
}