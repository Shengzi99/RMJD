#include<stdio.h>
#include<string.h>

int count[10];

int main(){
    int n, m;
    scanf("%d",&n);
    while (n--){
        scanf("%d", &m);
        memset(count, 0, sizeof(count));
        for(int i=m;i>0;i--){
            int cur=i;
            while(cur){
                count[cur%10]++;
                cur /= 10;
            }
        }
        for(int i=0;i<9;i++){
            printf("%d ", count[i]);
        }
        printf("%d\n", count[9]);
    }

    return 0;    
}