#include<cstdio>
#include<cstring>

using namespace std;

char buff[5][6];

void swapc(char &a, char &b){
    char tmp  = a;
    a = b;
    b = tmp;
}

void printbuff(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%c", buff[i][j]);
            if(j<4) printf(" ");
        }
        printf("\n");
    }
}

int main(){

#ifdef LOCAL
    freopen("3-5.in", "r", stdin);
    freopen("3-5.out", "w", stdout);
#endif
    int count = 0;
    while(1){
        scanf("%[^\n]%*c", buff[0]);
        if(strchr(buff[0], 'Z')) break;
        buff[0][4] = (buff[0][4]=='\0')?' ':buff[0][4];
        buff[0][5] = '\0';
        for(int i=1;i<5;i++){
            scanf("%[^\n]%*c", buff[i]);
            buff[i][4] = (buff[i][4]=='\0')?' ':buff[i][4];
            buff[i][5] = '\0';
        }
        if(count) printf("\n");
        printf("Puzzle #%d:\n", ++count);

        int bx,by;
        for(int i=0;i<5;i++){
            if(char *bp = strchr(buff[i], ' ')){
                bx = bp-buff[i];by = i;break;
            }
        }
        // printf("(%d,%d)", bx, by);

        int mov;
        int ill=0;
        while((mov=getchar())!='0'){
            if(ill) continue;
            switch (mov){
            case 'A':
                if(by<1){
                    ill = 1;
                    continue;
                }
                swapc(buff[by][bx], buff[by-1][bx]);by -= 1;break;
            case 'B':
                if(by>3){
                    ill = 1;
                    continue;
                }
                swapc(buff[by][bx], buff[by+1][bx]);by += 1;break;
            case 'R':
                if(bx>3){
                    ill = 1;
                    continue;
                }
                swapc(buff[by][bx], buff[by][bx+1]);bx += 1;break;
            case 'L':
                if(bx<1){
                    ill = 1;
                    continue;
                }
                swapc(buff[by][bx], buff[by][bx-1]);bx -= 1;break;
            case ' ':
            case '\n':
                break;
            default:
                ill = 1;
            }
        }
        if(ill) printf("This puzzle has no final configuration.\n");
        else printbuff();

        mov = getchar();
        while(mov!='\n'){
            if(mov=='Z') return 0;
            mov = getchar();
        }
    }
    return 0;
}