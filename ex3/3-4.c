#include<stdio.h>
#include<string.h>
#define nmax 100

char buff[nmax];
int main(){
#ifdef LOCAL
    freopen("3-4.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    while(n--){
        scanf("%s", buff);
        int len = strlen(buff);
        int pass, min_t=len;
        for(int t=1;t<len;t++){
            pass = 1;
            for(int j=len-1-t;j>-1;j--){
                if(buff[j]!=buff[j+t]){
                    pass = 0;
                    break;
                }
            }
            if(!pass || (len % t != 0)) continue;
            min_t = t;
            break;
        }
        printf("%d\n", min_t);
        if(n) printf("\n");
    }
    
    return 0;
}