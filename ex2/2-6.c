#include<stdio.h>

int main(){
    int j, k, l;
    int a, b, c, d, e, f, g, h, i;
    for(j=123;j<=329;j++){
        a = j/100, b = j/10%10, c=j%10;
        if(a==b || a==c || b==c) continue;
        k = j*2;
        l = j*3;
        d = k/100, e = k/10%10, f = k%10;
        g = l/100, h = l/10%10, i = l%10;

        /*若重复，必有未出现，只需验证1-9是否都出现*/
        for(int x=1;x<10;x++)
            if(x!=a && x!=b && x!=c && x!=d && x!=e && x!=f && x!=g && x!=h && x!=i)
                goto outer;
        printf("%d %d %d\n", j, k, l);

    outer:;       
    }
    return 0;
}