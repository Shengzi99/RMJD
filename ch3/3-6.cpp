#include<stdio.h>
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
char map[128];

int main(){
    for(int i=0;i<sizeof(s)-2;i++)
        map[s[i+1]] = s[i];
    char c;
    while((c = getchar()) != EOF){
        printf("%c", (c<33 || c==127) ? c:map[c]);
    }

    return 0;
}