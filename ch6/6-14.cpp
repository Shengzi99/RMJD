#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#define nmax 10
#define RCD2I(r,c,d) ((r)*100+(c)*10+(d))
#define I2R(p) ((p)/100)
#define I2C(p) ((p)%100/10)
#define I2D(p) ((p)%10)
#define D2N(v,d) (((v)>>(d*4))&7)
#define CLEAR(v,d,n) ((v)&=(~(1<<((d*4)+n))))
#define SET(v,d,n) ((v)|=(1<<((d*4)+n)))
#define NEXTD(d,n) (((d)+4+(n)-1)%4)
using namespace std;

const char *DIR = "NESW";
const char *NEXT= "LFR";
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
int M[nmax+1][nmax+1];
queue<int> Q;
map<int,int> P;
int sr,sc,sd,er,ec,ed; bool hasSol; char name[30]; char sdir;

void printM(){
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            printf("%4x ", M[i][j]);
        }
        putchar('\n');
    }
}
void visit(int r, int c, int d){
    int nxt = D2N(M[r][c], d); if(!nxt) return;
    int nxt_d,nxt_r,nxt_c;
    for(int n=0;n<3;n++){
        if(nxt&(1<<n)){
            nxt_d = NEXTD(d,n);
            nxt_r = r+dr[nxt_d];
            nxt_c = c+dc[nxt_d];
            if(!P.count(RCD2I(nxt_r,nxt_c,nxt_d))){
                Q.push(RCD2I(nxt_r,nxt_c,nxt_d));
                P[RCD2I(nxt_r,nxt_c,nxt_d)] = RCD2I(r,c,d);
                CLEAR(M[r][c],d,n);
                if( (nxt_r==er)&&(nxt_c==ec) ) {hasSol = true; ed=nxt_d;}
            }
        }
    }
}
void bfs(int r, int c, int d){
    P[RCD2I(r,c,d)] = RCD2I(sr,sc,4); 
    if( (r==er)&&(c==ec) ) {hasSol=true; ed=d;}
    Q.push(RCD2I(r,c,d)); int front;
    while(Q.size() && (!hasSol)){
        front = Q.front(); Q.pop();
        visit(I2R(front), I2C(front), I2D(front));
    }
}
void initM(){
    memset(M, 0, sizeof(M)); P.clear(); queue<int>().swap(Q);
    int r, c; char dn[5]; int d, n, i;
    while( scanf("%d", &r) && r && scanf("%d", &c) ){
        while( scanf("%s", dn) && dn[0]!='*' ){
            d = strchr(DIR, dn[0])-DIR; i=0;
            while(dn[++i]!='\0'){
                n = strchr(NEXT, dn[i])-NEXT;
                SET(M[r][c],d,n);
            }
        }
    }
    while(getchar()!='\n');
}
void printPath(){
    stack<int> S; int si = RCD2I(sr,sc,4), ei = RCD2I(er,ec,ed); int curi=ei, topi;
    S.push(ei);
    while( (curi=P[curi]) != si) S.push(curi);
    S.push(si);
    int count = 0;
    while(S.size()){
        if(count%10==0) putchar(' ');
        topi = S.top(); S.pop();
        printf(" (%d,%d)", I2R(topi), I2C(topi));
        if((++count)%10==0) printf("\n");
    }
    putchar('\n');
}

int main(){ 
#ifdef LOCAL
    freopen("6-14.in", "r", stdin);
#endif
    while( (scanf("%s", name)==1) && !(name[0]=='E'&&name[1]=='N'&&name[2]=='D'&&name[3]=='\0')){
        scanf("%d%d %c%d%d", &sr, &sc, &sdir, &er, &ec); sdir = strchr(DIR, sdir)-DIR;
        hasSol = false; initM();
        bfs(sr+dr[sdir], sc+dc[sdir], sdir);
        printf("%s\n", name);
        if(hasSol) printPath(); else printf("  No Solution Possible\n");
    }
    return 0;
}