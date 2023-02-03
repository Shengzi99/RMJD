#include<stdio.h>
#define INF 1000000000
int main(){

#ifdef LOCAL
    freopen("./2-10.in", "r", stdin);
    freopen("./2-10.out", "w", stdout);
#endif

    int x, n = 0, min = INF, max = -INF, s = 0;
    while(scanf("%d", &x) == 1){
        s += x;
        if(x < min) min = x;
        if(x > max) max = x;
        n++;
    }
    printf("%d %d %.3f\n", min, max, (double)s/n);
    return 0;
}