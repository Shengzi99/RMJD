#include<cstdio>
unsigned int getaddr(){
    unsigned int a,b,c,d;
    scanf("%d.%d.%d.%d%*c", &a,&b,&c,&d);
    return (a<<24) | (b<<16) | (c<<8) | d;
}
void putaddr(unsigned int a){
    printf("%d.%d.%d.%d\n", a/(1<<24), a/(1<<16)%256, a/(1<<8)%256, a%256);
}
int main(){
#ifdef LOCAL
    freopen("4-4.in", "r", stdin);
    freopen("4-4.out", "w", stdout);
#endif
    int m; unsigned int mask, addr;
    while( scanf("%d%*c", &m)==1 ){
        mask=~0; addr=getaddr();
        while(--m) addr &= (mask &= ~(addr^getaddr()));
        unsigned int i=(1<<31);
        while(i && (i&mask)) i>>=1;
        if(~mask) mask = ~((i<<1)-1);
        putaddr(addr&mask);putaddr(mask);
    }
}