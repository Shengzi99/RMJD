#include<cstdio>
#include<queue>
using namespace std;
queue<long long> Q;
int main(){
#ifdef LOCAL
    freopen("7-3.in", "r", stdin);
    freopen("7-3.out", "w", stdout);
#endif
    int k,y;
    while(scanf("%d", &k)==1){
        queue<long long>().swap(Q);
        for(y=k+1;y<=2*k;y++) if(k*y%(y-k)==0) Q.push( (long long)(k*y/(y-k))*100000+y );
        printf("%ld\n", Q.size());
        while(!Q.empty()) {printf("1/%d = 1/%lld + 1/%lld\n", k, Q.front()/100000, Q.front()%100000); Q.pop();}
    }
    return 0;
}