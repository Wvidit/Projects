#include <stdio.h>

void reverse( char* input);

int main()
{
    char *s;

    printf("Enter string:");
    scanf("%s",s);

    reverse(s);
}

void reverse( char* input)
{ 
    int len;
    for(int i = 0; ; i++)
    {
        if( input[i] == '\0')
        {
            len = i;
            break;
        }
    }
    for( int i = len; i >= 0 ; i--)
    {
        printf("%c", input[i] );
    }
}