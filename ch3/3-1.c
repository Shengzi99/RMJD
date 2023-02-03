#include<stdio.h>
#define maxn 105
int a[maxn];

int main(){
    int input, n=0;
    while(scanf("%d", &input)!=EOF)
        a[n++] = input;
    for(int i=n-1;i>-1;i--)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}