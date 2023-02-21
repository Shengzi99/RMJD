#include<cstdio>
#include<cstdlib>
#include<cstring>
#define maxn 55
#define maxm 55
#define maxt 205
#define MIN(A,B) ((A)<(B)?(A):(B))
#pragma comment(linker, "/STACK:1024000000,1024000000") 

int N,T,t[maxn],M1,d[maxm],M2,e[maxm];
int D[maxt][maxn];
bool hasTrain[2][maxt][maxn];

void getData(){
    scanf("%d",&T); 
    for(int i=1;i<N;i++) scanf("%d", &t[i]);
    scanf("%d", &M1); for(int i=1;i<=M1;i++) scanf("%d", &d[i]);
    scanf("%d", &M2); for(int i=1;i<=M2;i++) scanf("%d", &e[i]);
}

int dp(int i, int j){
    if(i > T) return 1<<29;
    if(D[i][j]==-1){
        D[i][j] = ( (D[i+1][j]==-1)?dp(i+1,j):D[i+1][j] ) + 1;
        if(j<N && hasTrain[0][i][j] && i+t[j]<=T)
            D[i][j] = MIN(D[i][j], ( (D[i+t[j]][j+1]==-1)?dp(i+t[j],j+1):D[i+t[j]][j+1] ));
        if(j>1 && hasTrain[1][i][j] && i+t[j-1]<=T)
            D[i][j] = MIN(D[i][j], ( (D[i+t[j-1]][j-1]==-1)?dp(i+t[j-1],j-1):D[i+t[j-1]][j-1] ));
    }
    return D[i][j];
}
int main(){
#ifdef LOCAL
    freopen("9-1.in", "r", stdin);
#endif
    int cnum=0;
    while(scanf("%d", &N)==1 && N){
        getData(); memset(D, -1, sizeof(D)); memset(hasTrain, 0, sizeof(hasTrain)); D[T][N]=0;
        int ttmp;
        for(int i=1;i<=M1;i++){
            ttmp = d[i]; hasTrain[0][ttmp][1] = true;
            for(int j=1;j<N;j++) hasTrain[0][ttmp+=t[j]][j+1]=true;
        }
        for(int i=1;i<=M2;i++){
            ttmp = e[i]; hasTrain[1][e[i]][N]=true;
            for(int j=N-1;j;j--) hasTrain[1][ttmp+=t[j]][j]=true;
        }
        printf("Case Number %d: ", ++cnum);
        dp(0,1);
        if(D[0][1]>(1<<29)) printf("impossible\n");
        else printf("%d\n", D[0][1]);
    }
    return 0;
}