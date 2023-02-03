#include<stdio.h>

int main(){
#ifdef LOCAL
    freopen("2-4.in", "r", stdin);
    // freopen("2-4.out", "w", stdout);
#endif

    long long n, m;
    while(scanf("%lld %lld", &n, &m)==2 && (n+m)!=0){
        float sum=0;
        for(long long i=n;i<=m;i++){
            sum += 1.0/(i*i);
        }
        printf("%.5f\n", sum);
    }
    return 0;
}