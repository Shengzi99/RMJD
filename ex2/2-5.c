#include<stdio.h>

int main(){
#ifdef LOCAL
    freopen("2-5.in", "r", stdin);
    // freopen("2-5.out", "w", stdout);
#endif

    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c)==3 && (a+b+c)!=0){
        c--;
        printf("%d.", a/b);
        while(c--){
            a = a%b*10;
            printf("%d", a/b);
        }
        a = a%b*10;
        /*末位四舍五入*/
        printf("%d\n", a/b+(int)(a%b*10/b>4));
    }
    return 0;
}