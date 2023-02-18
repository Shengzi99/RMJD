#include<cstdio>
#include<cstring>
#define P2I(I0,I1,I2,I3,I4) ((I0*10000) + (I1*1000) + (I2*100) + (I3*10) + I4)

int cnt[10];
bool is_valid(int i0, int i1, int i2, int i3, int i4, int n){
    memset(cnt , 0, sizeof(cnt));
    int div = n * P2I(i0,i1,i2,i3,i4);
    cnt[i0]++;cnt[i1]++;cnt[i2]++;cnt[i3]++;cnt[i4]++;
    if(div>98765) return false;
    for(int i=0;i<5;i++) {cnt[div%10]++; div/=10;}
    for(int i=0;i<10;i++) if(cnt[i]>1 || cnt[i]==0) return false;
    return true;
}
int main(){
#ifdef LOCAL
    freopen("7-1.in", "r", stdin);
#endif
    int n, cnum=0;
    while(scanf("%d", &n)==1 && n){
        if(cnum++) putchar('\n');
        int solnum=0;
        for(int i0=0;i0<10;i0++)
            for(int i1=0;i1<10;i1++){
                if(i1==i0) continue;
                for(int i2=0;i2<10;i2++){
                    if( (i2==i0) || (i2==i1) ) continue;
                    for(int i3=0;i3<10;i3++){
                        if( (i3==i0) || (i3==i1) || (i3==i2) ) continue;
                        for(int i4=0;i4<10;i4++){
                            if( (i4==i0) || (i4==i1) || (i4==i2) || (i4==i3) ) continue;
                            if(is_valid(i0,i1,i2,i3,i4,n)){
                                solnum++;
                                printf("%05d / %05d = %d\n", n*P2I(i0,i1,i2,i3,i4),P2I(i0,i1,i2,i3,i4),n);
                            }
                        }
                    }
                }
            }
        if(!solnum) printf("There are no solutions for %d.\n", n);
    }
}