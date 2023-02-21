#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 100005

int H[maxn];
int main(){
#ifdef LOCAL
    freopen("8-5.in", "r", stdin);
#endif
    int n; long long w;
    while(scanf("%d", &n)==1 && n){
        w=0;
        for(int i=0;i<n;i++) scanf("%d", &H[i]);
        for(int i=0;i<n;i++) {w+=abs(H[i]); H[i+1]+=H[i];}
        printf("%lld\n", w);
    }
    return 0;
}