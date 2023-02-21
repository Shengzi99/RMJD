#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 35
#define MAX(A,B) ((A)>(B)?(A):(B))
using namespace std;
typedef vector<int> Block;

const int bot[3][3] = {{0,1,2},{0,2,1},{1,2,0}};
int n, DP[maxn][3];
Block B[maxn];

int dp(){
    int hmax = 0; memset(DP, 0, sizeof(DP));
    for(int i=0;i<n;i++)for(int j=0;j<3;j++) hmax = MAX(DP[i][j] = B[i][bot[j][2]], hmax);
    for(int fuck=0;fuck<n;fuck++)for(int i=0;i<n;i++)for(int j=0;j<3;j++){
        for(int k=0;k<n;k++)for(int l=0;l<3;l++){
            if(B[k][bot[l][0]]<B[i][bot[j][0]] && B[k][bot[l][1]]<B[i][bot[j][1]])
                hmax = MAX(DP[i][j] = MAX(DP[i][j], B[i][bot[j][2]]+DP[k][l]), hmax);
        }
    }
    return hmax;
}

int main(){
#ifdef LOCAL
    freopen("9-2.in", "r", stdin);
    freopen("9-2.out", "w", stdout);
#endif
    int cnum=0,tmp[3];
    while(scanf("%d", &n)==1 && n){
        for(int i=0;i<n;i++){
            scanf("%d%d%d", &tmp[0],&tmp[1],&tmp[2]); sort(tmp, tmp+3);
            B[i] = Block(tmp,tmp+3);
        }
        sort(B,B+n);
        printf("Case %d: maximum height = %d\n", ++cnum, dp());
    }
    return 0;
}