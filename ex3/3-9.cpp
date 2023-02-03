#include<cstdio>
#include<cstring>
char s[100000];
char t[100000];
int main(){
#ifdef LOCAL
    freopen("3-9.in", "r", stdin);
#endif
    while (scanf("%s%s", s, t)==2){
        int lp = -1, match=1;
        int slen = strlen(s);
        for(int i=0;i<slen;i++){
            while(1){
                lp++;
                if(t[lp]=='\0'){match = 0; break;}
                if(t[lp]==s[i]) break;
            }
        }
        printf("%s\n", match?"Yes":"No");
    }
    return 0;
}