#include<stdio.h>
#include<math.h>

int main(){
    printf("average input: ");
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("average:%.3f\n", (double)(a+b+c)/3);

    printf("temperature input: ");
    double f;
    scanf("%lf", &f);
    printf("celsius temperature: %.3f\n", 5*(f-32)/9 );

    printf("N sum input: ");
    int n;
    scanf("%d", &n);
    printf("N sum: %d\n", n*(n+1)/2);

    printf("sin & cos input: ");
    // int n;
    scanf("%d", &n);
    double arc = (double)n/180*acos(-1.0);
    printf("sin & cos: %.3f, %.3f\n", sin(arc), cos(arc));
    
    return 0;
}