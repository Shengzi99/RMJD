#include<stdio.h>
int main(){
    int c, count = 0;
    while((c = getchar()) != EOF){
        if(c == '"') printf((count = !count) ? "``" : "\"");
        else  printf("%c", c);
    }
    
    return 0;
}