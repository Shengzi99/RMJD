#include<cstdio>
using namespace std;

int main(){
    int N, D, I, num; scanf("%d", &N);
    for(int i=0;i<N;i++){
        num=1; scanf("%d%d", &D, &I); I--;
        while(--D){
            num = (num<<1) + (I&1);
            I >>= 1;
        }
        printf("%d\n", num);
    }
    return 0;
}