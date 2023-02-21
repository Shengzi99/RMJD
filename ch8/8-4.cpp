#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define MIN(A,B) ((A)<(B)?(A):(B))
#define MAX(A,B) ((A)>(B)?(A):(B))
using namespace std;

struct Rect{
    int i;
    int xl,yl,xr,yr;
    int px,py;
    Rect():i(0),xl(0),yl(0),xr(0),yr(0),px(0),py(0){}
    Rect(int i, int xl, int yl, int xr, int yr):i(i),xl(xl),yl(yl),xr(xr),yr(yr){}
    Rect & operator=(const Rect & b){i=b.i;xl=b.xl;yl=b.yl;xr=b.xr;yr=b.yr;px=b.px;py=b.py;return *this;}
};
struct Compx{
    bool operator()(Rect *&a, Rect *&b) const{
        if(a->xl==b->xl) return a->xr>b->xr;
        else return a->xl>b->xl;
    }
};
struct Compy{
    bool operator()(Rect *&a, Rect *&b) const{
        if(a->yl==b->yl) return a->yr>b->yr;
        else return a->yl>b->yl;
    }
};
int n; Rect R[5005];
priority_queue<Rect*,vector<Rect*>,Compx> Qx;
priority_queue<Rect*,vector<Rect*>,Compy> Qy;
bool solve(){
    Rect* tmp; int pos = Qx.top()->xl;
    while(!Qx.empty()){
        if(pos>Qx.top()->xr) return false;
        else{
            pos = Qx.top()->px = MAX(pos, Qx.top()->xl); Qx.pop();
            pos++;
            while(Qx.size() && (Qx.top()->xl<pos)){
                tmp = Qx.top(); Qx.pop();
                if(tmp->xr<pos) return false;
                else tmp->xl = MAX(pos,tmp->xl);
                Qx.push(tmp);
            }
        }
    }
    pos = Qy.top()->yl;
    while(!Qy.empty()){
        if(pos>Qy.top()->yr) return false;
        else{
            pos = Qy.top()->py = MAX(pos, Qy.top()->yl); Qy.pop();
            pos++;
            while(Qy.size() && (Qy.top()->yl<pos)){
                tmp = Qy.top(); Qy.pop();
                if(tmp->yr<pos) return false;
                else tmp->yl = MAX(pos,tmp->yl);
                Qy.push(tmp);
            }
        }
    }
    return true;
}
int main(){
#ifdef LOCAL
    freopen("8-4.in", "r", stdin);
#endif
    int a,b,c,d;
    while(scanf("%d", &n)==1 && n){
        priority_queue<Rect*,vector<Rect*>,Compx>().swap(Qx);
        priority_queue<Rect*,vector<Rect*>,Compy>().swap(Qy);
        for(int i=0;i<n;i++) {scanf("%d%d%d%d", &a,&b,&c,&d); R[i]=Rect(i,a,b,c,d);Qx.push(&R[i]);Qy.push(&R[i]);}
        if(solve()) for(int i=0;i<n;i++) printf("%d %d\n", R[i].px, R[i].py);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}