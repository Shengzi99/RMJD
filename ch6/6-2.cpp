#include<cstdio>
#include<queue>
#include<stack>
using namespace std;

queue<int> P;
stack<int> S;

int main(){
#ifdef LOCAL
    freopen("6-2.in", "r", stdin);
    freopen("6-2.out", "w", stdout);
#endif
    int n, in;
    while(scanf("%d", &n)==1 && n){
        while(1){
            queue<int>().swap(P); stack<int>().swap(S);
            scanf("%d", &in); if(!in) break;
            P.push(in); for(int i=1;i<n;i++) {scanf("%d", &in); P.push(in);}
            int i=1; S.push(i);
            while(i<=n){
                if(!S.empty() && P.front()==S.top()) {P.pop(); S.pop();}
                else S.push(++i);
            }
            printf("%s\n", (P.empty()?"Yes":"No"));
        }
        printf("\n");
    }
}