#include<stdio.h>
#define nmax 100

char buff[nmax];

int main(){
#ifdef LOCAL
    freopen("3-1.in", "r", stdin);
    freopen("3-1.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    while(n--){
        scanf("%s", buff);
        int score=0, sum=0;
        for(int i=0;buff[i]!='\0';i++){
            if(buff[i]=='O') score+=(++sum);
            else sum=0;
        }
        printf("%d\n", score);
    }

    return 0;
}