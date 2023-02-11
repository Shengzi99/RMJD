#include<cstdio>
#include<vector>
#define maxn 25
using namespace std;

int n;
vector<int> p[maxn];

void find_pos(int num, int &pi, int &h){
    for(pi=0;pi<n;pi++)
        for(h=0;h<p[pi].size();h++)
            if(p[pi][h]==num) return;
}
void ret_above(int pi, int h){
    for(int i=h+1;i<p[pi].size();i++)
        p[p[pi][i]].push_back(p[pi][i]);
    p[pi].resize(h+1);
}
void exec(char c1, int a, char c2, int b){
    int api,ah,bpi,bh;
    find_pos(a, api, ah); find_pos(b, bpi, bh);
    if(api==bpi) return;
    if(c1=='m') ret_above(api, ah);
    if(c2=='n') ret_above(bpi, bh);
    p[bpi].insert(p[bpi].end(), p[api].begin()+ah, p[api].end());
    p[api].resize(ah);
}
void printp(int n){
    for(int i=0;i<n;i++){
        printf("%d:", i);
        for(auto it=p[i].begin();it!=p[i].end();it++) printf(" %d", *it);
        putchar('\n');
    }
}

int main(){
#ifdef LOCAL
    freopen("5-2.in", "r", stdin);
    freopen("5-2.out", "w", stdout);
#endif
    int a,b; char comm1,comm2;
    while(scanf("%d%*c", &n)==1){
        for(int i=0;i<n;i++) {p[i].clear(); p[i].push_back(i);}
        while((comm1=getchar())!='q'){
            scanf("%*s%d%*c%*c%c%*s%d%*c", &a,&comm2,&b);
            exec(comm1, a, comm2, b);
        }
        printp(n);
        while((comm1=getchar())!='\n' && comm1!=EOF);
    }
}