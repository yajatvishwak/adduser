#ifndef DEFINATION_DOT_H /* This is an "include guard" */
#define DEFINATION_DOT_H /* prevents the file from being included twice. */
                         /* Including a header file twice causes all kinds */
                         /* of interesting problems.*/

/**
 * This is a function declaration.
 * It tells the compiler that the function exists somewhere.
 */
char *getfield(char *line, int num);
int str2int(char *s);
char *concat(const char *s1, const char *s2);

#endif /* FOO_DOT_H */