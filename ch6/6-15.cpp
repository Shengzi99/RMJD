#include<cstdio>
#include<cstring>
#include<stack>
#define maxn 105
using namespace std;

int V[maxn];
int E[maxn][maxn];
int topo[maxn];
int n, m, t;

bool dfs(int i){
    V[i] = -1;
    for(int j=n;j;j--)
        if(E[i][j]){
            if(V[j]==-1) return false;
            if(V[j]==0 && (!dfs(j))) return false;
        }
    V[i] = 1; topo[t++] = i;
    return true;
}
int main(){
#ifdef LOCAL
    freopen("6-15.in", "r", stdin);
#endif
    int i, j; bool is_dag;
    while( (scanf("%d%d", &n, &m)==2) && n ){
        memset(E, 0, sizeof(E)); memset(V, 0, sizeof(V)); is_dag = true; t = 0;
        while(m-- && scanf("%d%d", &i, &j)) E[i][j]=1;
        for(int s=1;s<=n && is_dag;s++) 
            if(!V[s]) is_dag = dfs(s);
        while(t--) {printf("%d", topo[t]); if(t) putchar(' ');}
        putchar('\n');
    }
    return 0;
}
