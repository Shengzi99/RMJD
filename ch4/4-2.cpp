#include<cstdio>
#include<cstring>
int a[26];
int main(){
#ifdef LOCAL
    freopen("4-2.in", "r", stdin);
#endif
    char ch;
    int r;
    int miss, win;
    while(scanf("%d", &r)==1 && r!=-1){
        getchar(); printf("Round %d\n", r); memset(a, 0, sizeof(a));
        while((ch=getchar())!='\n') a[ch-'a']=1;
        miss=0;
        while((ch=getchar())!='\n'){
            if(miss<7){
                if(a[ch-'a']!=1) miss++;
                else a[ch-'a'] = 2;
            }
        }
        win = 1;
        for(int i=0;i<26;i++) if(a[i]==1) win=0;
        if(win) printf("You win.\n");
        else printf("%s\n", (miss>6)?"You lose.":"You chickened out.");
    }
    return 0;
}