/*
 *  ==========================
 *  Finding length of a string
 *  ==========================
 */


#include <stdio.h>


int main()
 {
    char *s = "welcome";
    int i;
    for (i=0; s[i]!='\0'; i++){}

    printf("Length is: %d", i);

    return 0;
 }