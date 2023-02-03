#include<cstdio>
#include<cstring>
#define _min(a,b) (a)>(b)?(b):(a)
#define _max(a,b) (a)<(b)?(b):(a)

char master[100];
char driven[100];

int main(){
#ifdef LOCAL
    freopen("3-11.in", "r", stdin);
#endif
    int minlen;
    while(scanf("%s%s", master, driven)==2){
        int mlen=strlen(master), dlen=strlen(driven);
        minlen = mlen + dlen;
        for(int m_off=0;m_off<mlen;m_off++){
            int ok = 1; int i = 0;
            while(i<dlen && (m_off + i)<mlen){
                if(driven[i]+master[m_off+i]>99){ok = 0; break;}
                i++;
            }
            if(ok){
                minlen = _max(m_off + dlen, mlen);
                break;
            }
        }
        for(int d_off=0;d_off<dlen;d_off++){
            int ok = 1; int i = 0;
            while(i<mlen && (d_off + i)<dlen){
                if(master[i]+driven[d_off+i]>99){ok = 0; break;}
                i++;
            }
            if(ok){
                minlen = _min(minlen, _max(d_off + mlen, dlen));
                break;
            }
        }
        printf("%d\n", minlen);
    }
}