#include<cstdio>
#include<cstring>

#define nmax 25

int n, k, m;
char a[nmax];
int go(int p, int d, int t){
    while(t--){
        p = (n+p-1+d) % n + 1;
        if(a[p]==0) t++;
    }
    return p;
}

int main(){
#ifdef LOCAL
    freopen("4-3.in", "r", stdin);
#endif
    while(scanf("%d%d%d", &n, &k, &m)==3 && n!=0){
        memset(a, '1', sizeof(a));
        int left = n;
        int p1=n, p2=1;
        while(left){
            p1 = go(p1, 1, k);
            p2 = go(p2, -1, m);
            a[p1] = a[p2] = 0;
            printf("%3d", p1); left--;
            if(p1!=p2) {printf("%3d", p2); left--;}
            if(left) printf(",");
        }
        printf("\n");
    }

    return 0;
}