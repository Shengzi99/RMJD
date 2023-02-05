#include<cstdio>
#define CNUM(maxclen) ((1<<(maxclen+1))-1-(maxclen+1))
char DICT[CNUM(7)];

int getint(int n){
    int ret=0; char ch;
    while(n && ((ch=getchar())!=EOF))
        if(ch=='0' || ch=='1') {ret = (ret<<1)+(ch-'0'); n--;}
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("4-4.in", "r", stdin);
#endif
    int clen; int code; int offset; int stopnum;
    while(scanf("%[^\n]%*c", DICT)==1){
        while( (clen = getint(3)) ){
            offset = CNUM(clen-1); stopnum = (1<<clen)-1;
            while((code = getint(clen)) != stopnum)
                printf("%c", DICT[offset+code]);
        }
        putchar('\n'); getchar();
    }
    return 0;
}