#include<cstdio>
#include<cstring>
#define maxn 32
using namespace std;
char img[maxn][maxn];
int countpx(){
    int px=0;
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++) px += img[i][j];
    return px;
}
void build(int ulr, int ulc, int len){
    char ch = getchar();
    if(ch=='p'){
        build(ulr,ulc+(len>>1),len>>1);
        build(ulr,ulc,len>>1);
        build(ulr+(len>>1),ulc,len>>1);
        build(ulr+(len>>1),ulc+(len>>1),len>>1);
    }
    if(ch=='f')
        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++) img[ulr+i][ulc+j]=1;
}
int main(){
#ifdef LOCAL
    freopen("6-11.in", "r", stdin);
#endif
    int c; scanf("%d%*c", &c);
    while(c--){
        memset(img, 0, sizeof(img));
        build(0,0,maxn); getchar();
        build(0,0,maxn); getchar();
        printf("There are %d black pixels.\n", countpx());
    }
    putchar('\n'); return 0;
}