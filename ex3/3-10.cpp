#include<cstdio>
#include<cstring>
#include<unordered_map>

struct Surf{
    int h;
    int w;

    Surf():h(0),w(0){}
    Surf(int a, int b):h((a>b)?b:a),w((a>b)?a:b){}

    bool operator==(const Surf &b){
        return (this->h == b.h) && (this->w == b.w);
    }
    Surf operator=(const Surf &b){
        this->h = b.h; this->w = b.w;
        return *this;
    }
};

void print_allsf(Surf *s){
    for(int i=0;i<6;i++) printf("(%d,%d) ", s[i].h, s[i].w);
    printf("\n");
}

Surf sf[6];
int flag[6];
int main(){
#ifdef LOCAL
    freopen("3-10.in", "r", stdin);
#endif

    int in_a, in_b;
    std::unordered_map<int, int> ecount;
    while(scanf("%d%d", &in_a, &in_b)==2){
        ecount.clear();
        memset(flag, 0, sizeof(flag));
        int pass = 1;
        sf[0] = Surf(in_a, in_b);
        for(int i=1;i<6;i++){
            scanf("%d%d", &in_a, &in_b);
            sf[i] = Surf(in_a, in_b);
        }
        // print_allsf(sf);

        for(int i=0;i<6;i++){
            if(ecount.find(sf[i].h)==ecount.end()) ecount[sf[i].h] = 1;
            else ecount[sf[i].h]++;
            if(ecount.find(sf[i].w)==ecount.end()) ecount[sf[i].w] = 1;
            else ecount[sf[i].w]++;
        }
        for(int i=0;i<6;i++){
            if(!flag[i]){
                int j=-1;
                while(++j<6){
                    if(flag[j]||(i==j)) continue;
                    if(sf[j]==sf[i]){flag[i]=1,flag[j]=1;}
                }
            }
        }
        for(int i=0;i<6;i++){
            if(!flag[i]) {pass = 0; break;}
        }
        if(ecount.size()>3) pass = 0;
        for(auto h=ecount.begin();h!=ecount.end();h++){
            if(h->second % 4 != 0) pass = 0;
        }
        printf("%s\n", pass?"POSSIBLE":"IMPOSSIBLE");
    }
    return 0;
}