#include<cstdio>
#include<cstring>
#define maxn 10000

int hsum[maxn];
bool end;

void build(int p){
    int d; scanf("%d", &d);
    if(d==-1) return;
    end = false;
    hsum[p]+=d;
    build(p-1);
    build(p+1);
}
int main(){
    int c = 0;
    while(!end){
        memset(hsum, 0, sizeof(hsum)); end=true;
        build(maxn>>1);
        if(!end){
            printf("Case %d:\n", ++c);
            int i=-1; while(!hsum[++i]); printf("%d", hsum[i++]);
            while(hsum[i]) printf(" %d", hsum[i++]);
            putchar('\n'); putchar('\n');
        }
    }
}