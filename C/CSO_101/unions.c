#include <stdio.h>

union data {
    int sno;
    char name[50];
} class1;

int main() {
    
    printf("Enter no.: ");
    scanf("%d", &class1.sno);
    
    printf("Enter name: ");
    scanf("%s", class1.name);  
    printf("Name entered: %s\n", class1.name);

    return 0;
}
