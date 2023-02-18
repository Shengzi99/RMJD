#include<cstdio>
#include<cstring>

int n, S[18];
int main(){
#ifdef LOCAL
    freopen("7-2.in", "r", stdin);
#endif
    int cnum=0;
    while(scanf("%d", &n)==1){
        for(int i=0;i<n;i++) scanf("%d", &S[i]);
        int i=0, j=0; long long maxp=0,p;
        while(i<n){
            p=1;j=i;while(j<n){
                p*=S[j];
                maxp = (maxp<p)?p:maxp;
                j++;
            }
            i++;
        }
        printf("Case #%d: The maximum product is %lld.\n\n", ++cnum, maxp);
    }

}