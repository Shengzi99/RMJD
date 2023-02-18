#include<cstdio>
#include<cstring>
#include<unordered_map>
using namespace std;

int L[4][4005];
unordered_map<int,int> cnt;

int main(){
#ifdef LOCAL
    freopen("8-3.in", "r", stdin);
    freopen("8-3.out", "w", stdout);
#endif
    int cnum,n,nsum; scanf("%d", &cnum);
    while(cnum--){
        scanf("%d", &n); cnt.clear(); nsum=0;
        for(int i=0;i<n;i++) scanf("%d%d%d%d", &L[0][i], &L[1][i], &L[2][i], &L[3][i]);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cnt.count(-(L[2][i]+L[3][j]))) cnt[-(L[2][i]+L[3][j])]++;
                else cnt[-(L[2][i]+L[3][j])]=1;
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(cnt.count(L[0][i]+L[1][j])) nsum+=cnt[L[0][i]+L[1][j]];
            }
        printf("%d\n", nsum); if(cnum) putchar('\n');
    }
    return 0;
}