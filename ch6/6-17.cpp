#include<cstdio>
#include<cctype>
#include<cstring>
#define ISNODE(a) (a && isprint(a) && ((a)!='-') && ((a)!='|') && ((a)!=' ') && ((a)!='#'))
#define maxn 105

char T[maxn][maxn];

void inTrav(int i, int j){
    printf("%c(", T[i][j]); int lo,hi;
    if(T[i+1][j]=='|'){
        lo=j; while(lo && T[i+2][lo-1]=='-') lo--;
        hi=j; while(T[i+2][hi]=='-') hi++;
        for(int jj=lo;jj<hi;jj++){
            if(ISNODE(T[i+3][jj])) inTrav(i+3, jj);
        }
    }
    putchar(')');
}
int main(){
#ifdef LOCAL
    freopen("6-17.in", "r", stdin);
#endif
    int num, ch; scanf("%d%*c", &num);
    while(num--){
        int i=-1,j; memset(T, 0, sizeof(T));
        while(T[i++][0]!='#'){
            j=0;
            while((ch=getchar())!='\n' && ch!=EOF) T[i][j++]=ch;
        }
        j=0; while(T[0][j] && !ISNODE(T[0][j])) j++;
        if(T[0][j]==0) printf("()\n");
        else {putchar('('); inTrav(0, j); printf(")\n");}
    }
    return 0;
}