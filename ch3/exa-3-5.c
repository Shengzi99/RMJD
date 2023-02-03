#include<stdio.h>
#define nmax 100005
int t[nmax];

int main(){
#ifdef LOCAL
    freopen("exa-3-5.in", "r", stdin);
#endif
    int x, y;
    for(int i=nmax;i;i--){
        y = x = i;
        while(x){
            y+=x%10;
            x/=10;
        }
        if(y<nmax) t[y] = i;
    }

    int n, m;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &m);
        printf("%d\n", t[m]);
    }
    return 0;
}