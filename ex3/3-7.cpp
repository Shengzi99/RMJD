#include<cstdio>
#include<cstring>

#define nmax 1000

int count[4][nmax];
const char chmap[4] = {'A', 'C', 'G', 'T'};

int main(){
#ifdef LOCAL
    freopen("3-7.in", "r", stdin);
#endif
    int num;
    scanf("%d", &num);
    while(num--){
        int m, n;
        char ch;
        scanf("%d%d", &m, &n); getchar();
        while (m--){
            for(int i=0;i<n;i++){
                ch = getchar();
                switch(ch){
                case 'A':
                    count[0][i]++;break;
                case 'C':
                    count[1][i]++;break;
                case 'G':
                    count[2][i]++;break;
                case 'T':
                    count[3][i]++;break;
                }
            }
            getchar();
        }
        int error = 0;
        for(int i=0;i<n;i++){
            int imax=0;
            for(int j=1;j<4;j++) if(count[j][i]>count[imax][i]) imax=j;
            for(int j=0;j<4;j++) if(j!=imax) error+=count[j][i];
            printf("%c", chmap[imax]);
        }
        printf("\n%d\n", error);
        memset(count, 0, sizeof(count));
    }

    return 0;
}