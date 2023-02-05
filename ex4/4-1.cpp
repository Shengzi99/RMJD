#include<cstdio>
#include<cstring>
#define _min(a,b) ((a)<(b)?(a):(b))
#define _max(a,b) ((a)>(b)?(a):(b))

struct Piece{
    char type;
    int r;
    int c;
    Piece():type(0),r(0),c(0){}
    Piece(char t, int r, int c):type(t),r(r),c(c){}
    Piece & operator=(const Piece &p) {this->type=p.type; this->r=p.r, this->c=p.c; return *this;}
};

char board[11][10];
Piece reds[7];

int is_check_one(Piece &rp, int bgr, int bgc){
    switch(rp.type){
        case 'G':
            if(bgc != rp.c) return 0;
            for(int i=bgr+1;i<rp.r;i++) if(board[i][bgc]) return 0;
            break;
        case 'R':
            if(bgc == rp.c){
                int maxr = _max(bgr, rp.r), minr = _min(bgr, rp.r);
                for(int i=minr+1;i<maxr;i++) if(board[i][bgc]) return 0;
            }
            else if(bgr == rp.r){
                int maxc = _max(bgc, rp.c), minc = _min(bgc, rp.c);
                for(int i=minc+1;i<maxc;i++) if(board[bgr][i]) return 0;
            }
            else return 0;
            break;            
        case 'H':
            if( (bgr == rp.r+2) && !board[rp.r+1][rp.c]) 
                {if( (bgc != rp.c+1) && (bgc != rp.c-1) ) return 0;}
            else if( (bgr == rp.r-2) && !board[rp.r-1][rp.c])
                {if( (bgc != rp.c+1) && (bgc != rp.c-1) ) return 0;}
            else if( (bgc == rp.c+2) && !board[rp.r][rp.c+1])
                {if( (bgr != rp.r+1) && (bgr != rp.r-1) ) return 0;}
            else if( (bgc == rp.c-2) && !board[rp.r][rp.c-1])
                {if( (bgr != rp.r+1) && (bgr != rp.r-1) ) return 0;}
            else return 0;
            break;

        case 'C':
            int midcount = 0;
            if(bgc == rp.c){
                int maxr = _max(bgr, rp.r), minr = _min(bgr, rp.r);
                for(int i=minr+1;i<maxr;i++) {if(board[i][bgc]) midcount++;}
                if(midcount!=1) return 0;
            }
            else if(bgr == rp.r){
                int maxc = _max(bgc, rp.c), minc = _min(bgc, rp.c);
                for(int i=minc+1;i<maxc;i++) {if(board[bgr][i]) midcount++;}
                if(midcount!=1) return 0;
            }
            else return 0;
            break;    
    }

    return 1;
}

int is_check_all(int n, int bgr, int bgc){
    //判断非法黑将位置，若非法返回-1
    if(bgc<4 || bgc>6 || bgr<1 || bgr>3) return -1;
    int ret = 0;
    for(int i=0;i<n;i++){
        if( (bgr==reds[i].r) && (bgc==reds[i].c) ) continue;
        ret += is_check_one(reds[i], bgr, bgc);
    }
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("4-1.in", "r", stdin);
    freopen("4-1.out", "w", stdout);
#endif
    int n, bgr, bgc; int rgidx;
    // int count = 0;
    while(scanf("%d%d%d%*[^\n]", &n, &bgr, &bgc)==3 && n){
        // count ++;
        char t; int r,c; memset(board, 0, sizeof(board)); getchar();
        for(int i=0;i<n;i++){
            scanf("%c%d%d%*[^\n]", &t, &r, &c); getchar();
            // if(count == 995) printf("995(%d,%d) %c  %d  %d\n", bgr, bgc, t, r, c);
            reds[i] = Piece(t, r, c);
            board[r][c] = t;
            if(t == 'G') rgidx = i;
        }
        if(is_check_one(reds[rgidx], bgr, bgc)) {printf("NO\n"); continue;}
        
        printf("%s\n", ( is_check_all(n, bgr+1, bgc) && is_check_all(n, bgr-1, bgc) && is_check_all(n, bgr, bgc+1) && is_check_all(n, bgr, bgc-1) )?"YES":"NO");
    }
    return 0;
}