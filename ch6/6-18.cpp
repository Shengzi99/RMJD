#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define maxn 105
#define maxt 1005
#define INRANGE(I,J,K) ( ((I)>-1) && ((I)<xlim) && ((J)>-1) && ((J)<ylim) && ((K)>-1) && ((K)<zlim) )
#define IJKD2N(I,J,K,D) (((I)<<(24))|((J)<<(16))|((K)<<(8))|(D))
using namespace std;

struct Box{
    int x; int y; int z; int xlen; int ylen; int zlen;
    Box():x(0),y(0),z(0),xlen(0),ylen(0),zlen(0){}
    Box(int x, int y, int z, int xl, int yl, int zl):x(x),y(y),z(z),xlen(xl),ylen(yl),zlen(zl){}
    Box & operator=(const Box &b){x=b.x; y=b.y; z=b.z; xlen=b.xlen; ylen=b.ylen; zlen=b.zlen; return *this;}
};

const int dir[6][3]={{+1,0,0},{-1,0,0}, {0,+1,0},{0,-1,0}, {0,0,+1},{0,0,-1}};
int V[maxn][maxn][maxn];
int x2d[maxn], y2d[maxn], z2d[maxn], xlim, ylim, zlim;
int bx2x[maxt], by2y[maxt], bz2z[maxt];
vector<Box> B;
queue<int> Q;
int volume, surface;

void init(){
    B.clear(); memset(V, 0, sizeof(V)); 
    memset(x2d, 0, sizeof(x2d)); memset(y2d, 0, sizeof(y2d)); memset(z2d, 0, sizeof(z2d));
    memset(bx2x, 0, sizeof(bx2x)); memset(by2y, 0, sizeof(by2y)); memset(bz2z, 0, sizeof(bz2z));
}
void getBoxs(){
    int bnum; scanf("%d", &bnum); 
    int x,y,z,xl,yl,zl; 
    while(bnum--) {scanf("%d%d%d%d%d%d", &x,&y,&z,&xl,&yl,&zl); B.push_back(Box(x,y,z,xl,yl,zl));}
}
void _calcT(int *n2d, int *bn2n, int &nlim){
    sort(n2d+1, n2d+1+(B.size()*2));
    int p1, p2; p1=p2=1;
    // 对n2d所有出现的坐标值进行唯一化，并在过程中:
    //   1. 计算唯一化后n2d[i]和n2d[i+1]两坐标间隔存回n2d[i]
    //   2. 计算bn2n(即坐标n2d[i]到体块下标i的变换)
    while(n2d[p2]!=0){
        if(n2d[p1]==n2d[p2]) {p2++; continue;}
        bn2n[n2d[p1]] = p1;
        n2d[p1] = n2d[p2]-n2d[p1];
        p1++; n2d[p1] = n2d[p2];
    }
    bn2n[n2d[p1]] = p1; nlim=p1+1;
    // 把剩下的全置为0
    while(n2d[p1]!=0) {n2d[p1]=0; p1++;}
}
void calcTrans(){
    int i=1;
    for(auto it=B.begin();it!=B.end();it++){
        x2d[i]=it->x; y2d[i]=it->y; z2d[i]=it->z; i++;
        x2d[i]=it->x+it->xlen; y2d[i]=it->y+it->ylen; z2d[i]=it->z+it->zlen; i++;
    }
    _calcT(x2d, bx2x, xlim); _calcT(y2d, by2y, ylim); _calcT(z2d, bz2z, zlim);
}
void calcTotalVol(){
    int i,j,k; 
    i=0;while(x2d[++i]!=0){
        j=0;while(y2d[++j]!=0){
            k=0; while(z2d[++k]!=0) 
                    volume+=x2d[i]*y2d[j]*z2d[k];
        }
    }
}
void paintCopper(){
    for(auto it=B.begin();it!=B.end();it++)
        for(int i=bx2x[it->x];i<bx2x[it->x+it->xlen];i++)
            for(int j=by2y[it->y];j<by2y[it->y+it->ylen];j++)
                for(int k=bz2z[it->z];k<bz2z[it->z+it->zlen];k++)
                    V[i][j][k] = 1;
}
// dfs会爆栈
void dfs(int i, int j, int k, int d){
    if(V[i][j][k]==1){
        switch(d){
            case 0: case 1: surface+=y2d[j]*z2d[k]; break;
            case 2: case 3: surface+=x2d[i]*z2d[k]; break;
            case 4: case 5: surface+=x2d[i]*y2d[j]; break;
        }
        return;
    }
    V[i][j][k] = 2; volume-=x2d[i]*y2d[j]*z2d[k];
    for(d=0;d<6;d++)
        if(INRANGE(i+dir[d][0],j+dir[d][1],k+dir[d][2]) && V[i+dir[d][0]][j+dir[d][1]][k+dir[d][2]]!=2)
            dfs(i+dir[d][0],j+dir[d][1],k+dir[d][2],d);
}
void bfs(){
    int i,j,k,d,n; int ni,nj,nk; Q.push(IJKD2N(0,0,0,0)); V[0][0][0]=2;
    while(!Q.empty()){
        n=Q.front();Q.pop(); 
        i=n>>24, j=(n>>16)&255, k=(n>>8)&255, d=n&255;
        if(V[i][j][k]==1){
            switch(d){
                case 0: case 1: surface+=y2d[j]*z2d[k]; break;
                case 2: case 3: surface+=x2d[i]*z2d[k]; break;
                case 4: case 5: surface+=x2d[i]*y2d[j]; break;
            }
            continue;
        }
        volume-=x2d[i]*y2d[j]*z2d[k];
        for(d=0;d<6;d++){
            ni=i+dir[d][0]; nj=j+dir[d][1]; nk=k+dir[d][2];
            if(INRANGE(ni,nj,nk) && V[ni][nj][nk]!=2){
                Q.push(IJKD2N(ni,nj,nk,d)); 
                if(V[ni][nj][nk]==0) V[ni][nj][nk]=2;
            }
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("6-18.in", "r", stdin);
#endif
    int tnum; scanf("%d", &tnum);
    while(tnum--){
        volume = 0; surface = 0;
        init(); getBoxs(); calcTrans(); calcTotalVol(); paintCopper(); bfs();
        printf("%d %d\n", surface, volume);
    }
}