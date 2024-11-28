// file2.c
#include <stdio.h>
// Declare extern variable here and extern function
extern int globalVar;
extern void display();
int main() {
 printf("Value of globalVar in main function: %d\n", globalVar);
 globalVar = 20;
 display();
 return 0;
}
