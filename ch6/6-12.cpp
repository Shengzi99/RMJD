#include<cstdio>
#define INRANGE(a,b) (((a)>-1)&&((a)<m)&&((b)>-1)&&((b)<n))
#define maxmn 100
char M[maxmn][maxmn]; int m,n;
void DFS(int r, int c){
    if( (!INRANGE(r,c)) || (M[r][c]!='@') ) return;
    M[r][c] = 'v';
    DFS(r-1, c-1); DFS(r-1,c); DFS(r-1,c+1);
    DFS(r,c-1); DFS(r,c+1);
    DFS(r+1, c-1); DFS(r+1,c); DFS(r+1,c+1);
    return;
}
int main(){
#ifdef LOCAL
    freopen("6-12.in", "r", stdin);
#endif
    while((scanf("%d%d%*c", &m, &n)==2) && m){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) M[i][j] = getchar();
            getchar();
        }
        int conns = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(M[i][j]=='@'){
                    conns ++;
                    DFS(i,j);
                }
            }
        }
        printf("%d\n", conns);    
    }
    putchar('\n');
    return 0;
}