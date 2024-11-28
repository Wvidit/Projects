#include "Stdio.h"
int HCF(int a, int b)
{
    if (b == 0)
        return a;
    return HCF(b, a % b);
}

int main()

    int a, b;
    printf("Enter integers:");
    scanf("%d %d", &a, &b);

    printf("%d", HCF(a, b));
}