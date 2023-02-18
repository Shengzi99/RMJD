#pragma GCC optimize(3)
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<ctime>
#include<unordered_set>
#define LL long long
#define SEG(V,LO,HI) ( (V)&((-1LL<<(HI<<2))^(-1LL<<(LO<<2))) )
#define ELE(V,I) (((V)>>((I)<<2))&0xF)
#define BAD(PERM, I,J) ( ((ELE(PERM,I-1)+1)==ELE(PERM,I)) || (J<n && (ELE(PERM,J-1)+1)==ELE(PERM,J)) )
using namespace std;

struct Node{
    LL perm;
    int depth;
    Node(LL p, int d):perm(p),depth(d){}
};

const LL end_perm[10]={0,0x1,0x21,0x321,0x4321,0x54321,0x654321,0x7654321,0x87654321,0x987654321};
const LL mask[10]={0xF,0xF0,0xF00,0xF000,0xF0000,0xF00000,0xF000000,0xF0000000,0xF00000000,0xF000000000};
unordered_set<LL> visited;
queue<Node> Q;
int n;

LL get_perm(int n){
    LL perm=0; LL tmp;
    for(int i=0;i<n;i++) {scanf("%lld", &tmp); perm|=(tmp<<(i<<2));}
    return perm;
}
LL cutNpaste(LL value, LL lo, LL hi, LL p){ // p要小于lo
    LL s1 = SEG(value, 0, p);
    LL s2 = SEG(value, lo, hi) >> ((lo-p)<<2);
    LL s3 = SEG(value, p, lo) << ((hi-lo)<<2);
    LL s4 = SEG(value, hi, n);
    return s1|s2|s3|s4;
}
int h(LL perm){
    int h=0;
    for(int i=1;i<n;i++) if(ELE(perm,i)!=ELE(perm,i-1)+1) h++;
    if(ELE(perm,n-1)!=n) h++;
    return h;
}
int bfs(LL start){
    if(start==end_perm[n]) return 0;
    Q.push(Node(start,0)); LL f_perm, f_depth, new_perm;
    while(!Q.empty()){
        f_perm = Q.front().perm; f_depth=Q.front().depth; Q.pop(); visited.insert(f_perm);
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                for(int p=0;p<i;p++){
                    if( BAD(f_perm, i, j) ) continue;
                    new_perm = cutNpaste(f_perm, i, j, p);
                    if(new_perm==end_perm[n]) return f_depth+1;
                    if((n==9) && (3*(f_depth+1)+h(new_perm)>3*(n-3)) ) continue;
                    Q.push(Node(new_perm, f_depth+1));
                }
            }
        }
    }
    return n-1;
}
int main(){
#ifdef LOCAL
    freopen("7-9.in", "r", stdin);
#endif
    clock_t t = clock();
    LL start; int cnum=0;
    while(scanf("%d", &n)==1 && n){
        start = get_perm(n); visited.clear(); queue<Node>().swap(Q);
        // printf("%lx", end_perm[9]);
        // printf("%llx, %llx, %llx, %llx\n", start, ELE(start, 3), SEG(start, 3, 5), cutNpaste(start, 3, 5, 1));
        printf("Case %d: %d\n", ++cnum, bfs(start));        
    }
    printf("(%lfs)\n", (double)(clock()-t)/CLOCKS_PER_SEC);
    return 0;
}