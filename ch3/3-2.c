#include<stdio.h>
#include<string.h>
#include<time.h>
#define MAXN 1005
char a[MAXN];

int main(){

#ifdef LOCAL
    freopen("3-2.in", "r", stdin);
    freopen("3-2.out", "w", stdout);
#endif

    int n, k;
    while(scanf("%d %d", &n, &k)==2){
        memset(a, 0, n);
        for(int i=1;i<=k;i++){
            int j = i;
            while((j-1)<n){
                a[j-1] = !a[j-1];
                j+=i;
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]) printf("%d ", i+1);
        }
        // n++;
        // memset(a, 0, n);
        // for(int i=1;i<=k;i++){
        //     int j = i;
        //     while(j<n){
        //         a[j] = !a[j];
        //         j+=i;
        //     }
        // }
        // for(int i=1;i<n;i++){
        //     if(a[i]) printf("%d ", i);
        // }
        printf("\n");
    }
    freopen("/dev/tty", "w", stdout);
    printf("Time: %.6lf\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}