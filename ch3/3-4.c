#include<stdio.h>
#include<string.h>

int main(){
#ifdef LOCAL
    freopen("3-4.in", "r", stdin);
    freopen("3-4.out", "w", stdout);
#endif
    char s[11], buff[20];
    int count = 0;
    while(scanf("%s", s)==1){
        for(int i=111;i<1000;i++)
            for(int j=11;j<100;j++){
                sprintf(buff, "%d%d%d%d%d", i, j, i*(j/10), i*(j%10), i*j);
                    for(int k=0;buff[k]!='\0';k++){
                        if(strchr(s, buff[k])==NULL)    goto p1;
                    }
                    printf("<%d>\n%5d\nX%4d\n-----\n%5d\n%-5d\n-----\n%d\n\n", ++count, i, j, i*(j%10), i*(j/10), i*j);
p1:;
            }
    
        printf("The number of solutions = %d\n\n", count);
        count = 0;
        memset(s, 0, sizeof(s));
        memset(buff, 0, sizeof(buff));
    }
    return 0;
}