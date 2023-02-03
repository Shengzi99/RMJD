#include<stdio.h>
#include<string.h>
#include<math.h>
#define maxn 20
int a[maxn][maxn];
int main(){
    int n, x, y, tot = 0;
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    tot = a[x=0][y=n-1] = 1;
    while(tot<n*n){
        while(x+1<n && !a[x+1][y]) a[++x][y]=++tot;
        while(y-1>-1 && !a[x][y-1]) a[x][--y]=++tot;
        while(x-1>-1 && !a[x-1][x-1]) a[--x][y]=++tot;
        while(y+1<n && !a[x][y+1]) a[x][++y]=++tot;
    }
    for(int i=0;i<n;i++,printf("\n"))
        for(int j=0;j<n;j++)
            printf("%d ", a[i][j]);

    return 0;
}