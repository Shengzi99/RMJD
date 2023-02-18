#include<cstdio>
#include<cstring>

char B[2][50][50];

int main(){
    int n;
    while(scanf("%d",&n)==1){
        printf("2 %d %d\n", n,n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) putchar((i<26)?('A'+i):('a'+i-26));
            putchar('\n');
        }
        putchar('\n');
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) putchar((j<26)?('A'+j):('a'+j-26));
            putchar('\n');
        }
        // putchar('\n');
    }
}