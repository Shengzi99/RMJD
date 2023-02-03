#include<stdio.h>

int main(){
    long long input, iternum = 0;
    printf("input: ");
    scanf("%lld", &input);
    if(input < 1) return 0;
    while(1){
        if(input == 1) break;
        else iternum += 1;

        if(input%2==1) input = 3*input +1;
        else input /= 2;
    }
    printf("%lld\n", iternum);
    return 0;
}