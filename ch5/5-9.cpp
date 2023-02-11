#include<cstdio>
#include<vector>
#include<unordered_map>
#define PAIR(a,b) ( ((long long)a<<32) | (long long)(b) )
typedef long long LL;
using namespace std;

unordered_map<string, int> S2ID;
vector<string> ID2S;
unordered_map<LL, int> P2R;
int T[10010][15];
int ID(string s){
    if(S2ID.count(s)) return S2ID[s];
    ID2S.push_back(s); return S2ID[s]=(ID2S.size()-1);
}
int main(){
#ifdef LOCAL
    freopen("5-9.in", "r", stdin);
#endif
    int n,m; char ibuff[81];
    while(scanf("%d%d%*c", &n,&m)==2){
        S2ID.clear(); ID2S.clear();
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                scanf("%[^,\n]%*c", ibuff);
                T[r][c]=ID(string(ibuff));
            }
        }
        int PNF = 1; int r1, r2, c1, c2;
        for(c1=0;c1<m-1&&PNF;c1++){
            for(c2=c1+1;c2<m&&PNF;c2++){
                P2R.clear();
                for(r2=0;r2<n&&PNF;r2++){
                    if(P2R.count(PAIR(T[r2][c1], T[r2][c2]))){
                        PNF = 0; r1 = P2R[PAIR(T[r2][c1], T[r2][c2])]+1;
                    }else P2R[PAIR(T[r2][c1], T[r2][c2])] = r2;
                }
            }
        }
        if(PNF) printf("YES\n");
        else printf("NO\n%d %d\n%d %d\n", r1, r2, c1, c2);
    }
    return 0;
}
