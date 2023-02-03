#include<stdio.h>
#include<string.h>

#define nmax 1010
int ans[nmax];
int f_a[10];
int f_g[10];

int main(){

#ifdef LOCAL
    freopen("exa-3-4.in", "r", stdin);
    freopen("exa-3-4.out", "w", stdout);
#endif
    int n = 0, game=0;
    while(scanf("%d", &n)==1 && n)
    {
        memset(f_a, 0, sizeof(f_a));
        printf("Game %d:\n", ++game);
        for(int i=0;i<n;i++){
            scanf("%d", &ans[i]);
            f_a[ans[i]] ++;
        }
        int g_cur;
        while(1){
            int  match=0, all=0;
            memset(f_g, 0, sizeof(f_g));
            for(int i=0;i<n;i++){
                scanf("%d", &g_cur);
                f_g[g_cur] ++;
                match += (g_cur == ans[i]);
            }
            if(!g_cur) break;
            for(int i=0;i<10;i++) all+=(f_a[i]<f_g[i]?f_a[i]:f_g[i]);
            printf("    (%d,%d)\n", match, all-match);
        }
    }
    return 0;
}