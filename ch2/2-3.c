#include<stdio.h>

int main(){
    int i = 32;
    while(1){
        int p = i*i;
        if(p > 9999) break;
        if(p/1000==p/100%10 && p/10%10==p%10)
            printf("%d\n", p);
        i++;
    }
    return 0;
}