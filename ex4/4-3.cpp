#include<cstdio>
#include<cstring>
#define REVERSE(T) (((T)=='W')?'B':'W')
#define INRANGE(X,Y) ((X>0)&&(Y>0)&&(X<9)&&(Y<9))
#define GET_DX(DI) ((DI&128) || (DI&64) || (DI&32))?1:( ((DI&1) || (DI&16))?0:-1 )
#define GET_DY(DI) ((DI&1) || (DI&2) || (DI&128))?1:( ((DI&4) || (DI&64))?0:-1 )
char board[9][9];

int is_legal(char t, int x, int y, int di=0){
    if(board[x][y]!='-') return 0;
    //返回值低8位为对应8个方向是否合法. 参数di为判断指定方向; di为0时为判断全方向,返回值低8位从低到高对应从正右方起逆时针各方向
    int legal_di=0, count=-1;
    if(di){
        int dx = GET_DX(di); int dy = GET_DY(di);
        t=REVERSE(t);
        do{x+=dx; y+=dy;count++;}while(INRANGE(x,y) && board[x][y]==t);
        t=REVERSE(t);
        if(INRANGE(x,y) && board[x][y]==t && count) legal_di = di;
    }
    else legal_di = is_legal(t, x, y, 1) | is_legal(t, x, y, 2) | is_legal(t, x, y, 4) | is_legal(t, x, y, 8)
                  | is_legal(t, x, y, 16)| is_legal(t, x, y, 32)| is_legal(t, x, y, 64)| is_legal(t, x, y, 128);
    return legal_di;
}
int move(char t, int x, int y, int di){
    //调用时需要确保传入di合法
    int change_count=0;
    int dx, dy; int ox=x, oy=y;
    for(int cur_di=1;cur_di<256;cur_di<<=1)
        if(cur_di & di){
            x = ox; y = oy;
            dx = GET_DX(cur_di); dy = GET_DY(cur_di);
            x+=dx;y+=dy;
            while(board[x][y]!=t){
                board[x][y]=t;
                x+=dx;y+=dy;change_count++;
            }
        }
    return change_count;
}
void printboard(){
    for(int i=1;i<9;i++){
        for(int j=1;j<9;j++)
            putchar(board[i][j]);
        putchar('\n');
    }
}

int main(){
#ifdef LOCAL
    freopen("4-3.in", "r", stdin);
    freopen("4-3.out", "w", stdout);
#endif
    int games,bnum,wnum;
    scanf("%d%*[^\n]", &games);getchar();
    while(games--){
        memset(board, 0, sizeof(board));bnum=0;wnum=0;
        for(int i=1;i<9;i++){
            for(int j=1;j<9;j++)
                {board[i][j] = getchar(); if(board[i][j]=='W')wnum++; if(board[i][j]=='B')bnum++;}
            while(getchar()!='\n');
        }
        int x,y,legal_di,change_count,no_legal; char turn,comm;
        turn = getchar();while(getchar()!='\n');
        while((comm=getchar())!='Q'){
            switch(comm){
                case 'L':
                    while(getchar()!='\n');
                    no_legal=1;
                    for(x=1;x<9;x++)
                        for(y=1;y<9;y++)
                            if(is_legal(turn, x, y)) {if(!no_legal)printf(" "); printf("(%d,%d)", x,y); no_legal=0;}
                    if(no_legal) printf("No legal move.");
                    putchar('\n');
                    break;
                case 'M':
                    x = getchar()-'0'; y = getchar()-'0'; while(getchar()!='\n');
                    if(!(legal_di=is_legal(turn, x, y))) {turn = REVERSE(turn); legal_di=is_legal(turn, x, y);}
                    change_count = move(turn, x, y, legal_di);
                    if(turn=='W') {wnum+=(change_count+1); bnum-=change_count;}
                    else {bnum+=(change_count+1); wnum-=change_count;}
                    board[x][y] = turn; turn = REVERSE(turn);
                    printf("Black - %2d White - %2d\n", bnum, wnum);
            }
        }
        getchar();
        printboard();
        if(games) printf("\n");
    }
    return 0;
}