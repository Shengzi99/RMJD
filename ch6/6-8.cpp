#include<cstdio>
#include<cstring>
#include<map>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define nmax 10005
using namespace std;
int inSeq[nmax], postSeq[nmax], lc[nmax], rc[nmax], root;
long long sum;
map<long long, int> sum2n;
int readSeq(int *s){
    char ch=0; int i=0;
    while((ch!='\n') && (scanf("%d", &s[i])==1)) {ch = getchar(); i++;}
    return i;
}
int buildTree(int I_lo, int I_hi, int P_lo, int P_hi){
    if(I_lo==I_hi) return 0;
    int cur_root = postSeq[P_hi-1]; 
    int I_r = I_lo-1; while(inSeq[++I_r]!=cur_root);
    int rcNum = I_hi - (I_r+1);
    sum += cur_root;
    if((I_hi-I_lo)==1){
        if(sum2n.count(sum)) sum2n[sum] = MIN(sum2n[sum], cur_root);
        else sum2n[sum]=cur_root;
    }
    lc[cur_root] = buildTree(I_lo, I_r, P_lo, P_hi-1-rcNum);
    sum -= lc[cur_root];
    rc[cur_root] = buildTree(I_r+1, I_hi, P_hi-1-rcNum, P_hi-1);
    sum -= rc[cur_root];
    return cur_root;
}
int main(){
#ifdef LOCAL
    freopen("6-8.in", "r", stdin);
#endif
    int n;
    while((n=readSeq(inSeq)) && readSeq(postSeq)){
        sum2n.clear(); sum=0; memset(rc, 0, sizeof(rc)); memset(lc, 0, sizeof(lc));
        root = buildTree(0, n, 0, n);
        printf("%d\n", sum2n.begin()->second);
    }
    return 0;
}