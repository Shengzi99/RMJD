#include<cstdio>
#include<cstring>
char a[100];
int n, L, cnt, len;
bool is_easy(int lo, int hi){
    int p1=lo, p2=lo+((hi-lo)>>1);
    while(p2<hi) if(a[p1++]!=a[p2++]) return false;
    return true;
}
void dfs(int cur){
    for(int i=0;i<L && (cnt!=n);i++){
        bool hard=true;
        a[cur] = 'A'+i;
        for(int j=2;j<=cur+1 && hard;j+=2) hard = !is_easy(cur+1-j,cur+1);
        if(hard){
            cnt++;
            if(cnt==n) {len=cur+1; return;}
            dfs(cur+1);
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("7-5.in", "r", stdin);
#endif
    while(scanf("%d%d", &n, &L) && n){
        memset(a, 0, sizeof(a)); cnt=0;
        dfs(0);
        for(int i=0;i<len;i++){
            if(i && (i%64==0)) putchar('\n');
            else if(i && (i%4==0)) putchar(' ');
            putchar(a[i]);
        }
        printf("\n%d\n", len);
    }
    return 0;
}