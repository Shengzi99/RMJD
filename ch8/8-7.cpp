#include<cstdio>
#include<cstring>
#include<unordered_set>
#define maxn 1000005
#define MAX(A,B) ((A)>(B)?(A):(B))
using namespace std;

int P[maxn];
unordered_set<int> S;
int main(){
#ifdef LOCAL
    freopen("8-7.in", "r", stdin);
#endif
    int cnum,n; unsigned smax; scanf("%d", &cnum);
    while(cnum--){
        S.clear(); smax=0; scanf("%d", &n);
        for(int i=0;i<n;i++) scanf("%d", &P[i]);
        int p1=0,p2=0;
        while(p2<n){
            while(p2<n && S.count(P[p2])==0) S.insert(P[p2++]);
            smax = MAX(smax,S.size());
            while(P[p1]!=P[p2]) S.erase(P[p1++]);
            p1++;p2++;
        }
        printf("%d\n", smax);
    }
    return 0;
}