#include <stdio.h>
#include <math.h>

double distance(double b[], double c[]);
double area(double a1[], double a2[], double a3[]);

int main()
{
    double p1[2], p2[2], p3[2], test[2];
    double d1, d2, d3, m1, m2, m3;

    printf("Enter point:");
    scanf("%lf %lf", &p1[0], &p1[1]);
    printf("Enter point:");
    scanf("%lf %lf", &p2[0], &p2[1]);
    printf("Enter point:");
    scanf("%lf %lf", &p3[0], &p3[1]);

    d1 = distance(p1,p2);
    d2 = distance(p2,p3);
    d3 = distance(p1,p3);

    if( d1 < d2 + d3 && d2 < d1 + d3 && d3 < d1 + d2)
    {
        printf("Valid points.\n");
        printf("Area is %f\n", area( p1, p2, p3));
    }

    printf("Enter point:");
    scanf("%lf %lf",&test[0],&test[1]);
    m1 = area(p1, p2, test);
    m2 = area(p1, test, p3);
    m3 = area(test, p2, p3);

    if( m1 + m2 + m3 == area( p1, p2, p3))
    {
        printf("Point lies in or inside the triangle.\n");
    }
}

double distance(double b[], double c[])
{
   return sqrt(pow(b[0] - c[0],2) + pow(b[1] - c[1],2)); 
}

double area(double a1[], double a2[], double a3[])
{
    double d1 = distance( a1, a2);
    double d2 = distance( a2, a3);
    double d3 = distance( a3, a1);
    double s = (d1 + d2 + d3)/2;

    return sqrt(s * (s - d1) * (s - d2) * (s - d3));
}