/*习题2-2 韩信点兵*/
#include<stdio.h>

int main(){

#ifdef LOCAL
    freopen("./2-2.in", "r", stdin);
    // freopen("./2-2.out", "w", stdout);
#endif
    
    int mod3, mod5, mod7;
    while(scanf("%d", &mod3)==1){
        scanf("%d", &mod5);
        scanf("%d", &mod7);

        int i=10;
        for(;i<101;i++){
            if(i%3==mod3 && i%5==mod5 && i%7==mod7){
                printf("%d\n", i);
                break;
            }
        }
        if(i==101) printf("No Answer\n");
    }

    return 0;
}