#include<stdio.h>
#include<string.h>
#include<ctype.h>

char buff[30];
const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};
char reverse(char c){
    if(isalpha(c)) return rev[c-'A'];
    return rev[c-'1'+26];
}

int main(){

#ifdef LOCAL
    freopen("3-7.in", "r", stdin);
    freopen("3-7.out", "w", stdout);
#endif

    int il, ir, mir=1, pal=1;
    while(scanf("%s", buff) == 1){
        il = -1, ir = strlen(buff), mir=1, pal=1;
        while((--ir)>=(++il)){
            if(buff[ir] != buff[il]) pal = 0;
            if(buff[ir] != reverse(buff[il])) mir = 0;
        }
        printf("%s -- is %s.\n\n", buff, msg[pal+2*mir]);
    }
    return 0;
}