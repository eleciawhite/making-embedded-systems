/*
 * stackoverflow.c
 *
 * This file shows some ways to cause a stack overflow.
 * 
 */


#include <stdio.h>
#define MAX_NAME_LENGTH 10 
// enter more than 10 characters to cause problems


void unbounded_fill_from_input(char* name)
{
    int i = 0;
    char ch;
    ch = getchar();
    while (ch != '\n') { // wait for new line
        name[i] = ch; i++;
        ch = getchar();
    }
    name[i] = NULL; // NULL terminate string
}
void trash_the_stack(void) 
{
    char name[MAX_NAME_LENGTH];
    printf("Hello! Tell me your name: ");
    unbounded_fill_from_input(name);
    printf("Hello %s\r\n", name);
}