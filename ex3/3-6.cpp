#include<cstdio>
#include<cstring>

using namespace std;
int num[10][10];
char chr[10][10];

int main(){
#ifdef LOCAL
    freopen("3-6.in", "r", stdin);
#endif

    int ny, nx, n=0;
    while (scanf("%d", &ny)==1 && ny && scanf("%d", &nx)==1){
        getchar();
        if(n) printf("\n");
        printf("puzzle #%d:\n", ++n);
        memset(num, 0, sizeof(num));
        for(int i=0;i<ny;i++,getchar())
            for(int j=0;j<nx;j++)   chr[i][j] = getchar();

        int count = 0;
        for(int i=0;i<ny;i++){
            for(int j=0;j<nx;j++){
                if(chr[i][j]=='*') continue;
                if(!i || !j) num[i][j]=(++count);
                if(i && j && (chr[i-1][j]=='*' || chr[i][j-1]=='*')) num[i][j]=(++count);
            }
        }
        // for(int i=0;i<ny;i++){
        //     for(int j=0;j<nx;j++){
        //         printf("%c ", chr[i][j]);
        //     }
        //     printf("\n");
        // }
        
        // for(int i=0;i<ny;i++){
        //     for(int j=0;j<nx;j++){
        //         printf("%-2d ", num[i][j]);
        //     }
        //     printf("\n");
        // }

        printf("Across\n");
        int word = 0;
        for(int i=0;i<ny;i++){
            for(int j=0;j<nx;j++){
                if(word){
                    if(chr[i][j]=='*') printf("\n"), word = 0;
                    else printf("%c", chr[i][j]); 
                }
                else{
                    if(num[i][j]) printf("%3d.%c",num[i][j],chr[i][j]), word=1;
                }
            }
            if(word) printf("\n"), word=0;
        }
        printf("Down\n");
        for(int i=0;i<ny;i++){
            for(int j=0;j<nx;j++){
                if((!i || chr[i-1][j]=='*') && num[i][j]){
                    printf("%3d.", num[i][j]);
                    int p = i;
                    while(p<ny && chr[p][j]!='*') printf("%c", chr[p++][j]);
                    printf("\n");
                }
            }
        }
    }
    
    return 0;
}