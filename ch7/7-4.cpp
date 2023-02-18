#include<cstdio>
#include<cstring>

const int is_prime[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1};
int a[20];
void print_PRR(int *a, int n, int cur){
    if(n==cur && is_prime[a[0]+a[n-1]]){
        for(int i=0;i<n;i++) {if(i) putchar(' '); printf("%d",a[i]);}
        putchar('\n');
        return;
    }
    if(cur==0) {a[0]=1; print_PRR(a,n,1); return;}
    for(int i=1;i<=n;i++){
        bool uniq=true;
        for(int j=0;j<cur;j++) if(a[j]==i) {uniq=false; break;}
        if(uniq && is_prime[i+a[cur-1]]){
            a[cur] = i;
            print_PRR(a,n,cur+1);
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("7-4.in", "r", stdin);
#endif
    int n, cnum=0;
    while(scanf("%d", &n)==1){
        memset(a, 0, sizeof(a));
        if(cnum) putchar('\n');
        printf("Case %d:\n", ++cnum);
        print_PRR(a, n, 0);
    }
    return 0;
}