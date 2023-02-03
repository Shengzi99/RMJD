#include<stdio.h>

int main(){
    // freopen("2-3.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int line = n*2-1;
    int pre = 0;
    while(n--){
        for(int i=0;i<line;i++){
            if(i<pre) printf(" ");
            else if(i<pre+n*2+1) printf("#");
            else printf(" ");
        }
        printf("\n");
        pre++;
    }
    return 0;
}