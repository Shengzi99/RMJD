#include<stdio.h>
#include<math.h>

int main(){
    for(int i=1000;i<9999;i++){
        int s = floor(sqrt(i) + 0.5);
        if(s*s == i && i/1000==i/100%10 && i/10%10==i%10)
            printf("%d\n", i);
    }
    return 0;
}