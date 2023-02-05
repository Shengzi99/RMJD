#include<cstdio>
#include<cstring>
#define nmax 10

int rlen[nmax][nmax];
int dlen[nmax][nmax];

void printrd(){
    for(int i=0;i<nmax;i++){
        for(int j=0;j<nmax;j++)
            printf("(%d,%d)", rlen[i][j], dlen[i][j]);
        printf("\n");
    }
}

int main(){
#ifdef LOCAL
    freopen("4-2.in", "r", stdin);
#endif
    int n, m, pnum=0;
    while(scanf("%d%d%*c", &n,&m)==2){
        memset(rlen, 0, sizeof(rlen)); memset(dlen, 0, sizeof(dlen));
        char ch; int i,j;
        if(pnum) printf("\n**********************************\n\n");
        printf("Problem #%d\n\n", ++pnum);
        while(m--){
            scanf("%c%d%d%*[^\n]", &ch, &i, &j);getchar();
            switch(ch){
                case 'H':
                    do {rlen[i][j]=rlen[i][j+1]+1; j--;}
                    while(j && rlen[i][j]);
                    break;
                case 'V':
                    do {dlen[j][i]=dlen[j+1][i]+1; j--;}
                    while(j && dlen[j][i]);
            }
        }
        int count; int none=1;
        for(int len=1;len<n;len++){
            count = 0;
            for(i=1;i<n-len+1;i++)
                for(j=1;j<n-len+1;j++)
                    if( (rlen[i][j]>=len) && (dlen[i][j]>=len) && (rlen[i+len][j]>=len) && (dlen[i][j+len]>=len) ) count++;
            if(count) {printf("%d square (s) of size %d\n", count, len); none=0;}
        }
        if(none) printf("No completed squares can be found.\n");
    }

    return 0;
}