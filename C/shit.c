#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union something{ 
    int n;
    char m;
}u = {65};

void main()
{
    printf("%d", strstr("abc","bc"));
}