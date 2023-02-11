#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#define LLEN 60
using namespace std;

vector<string> F;
char ibuff[LLEN];
int maxlen;

void printF(const vector<string> &f){
    int i=60; while(i--) putchar('-'); putchar('\n');
    int ncol = (LLEN+2)/(maxlen+2);
    int nrow = (int)ceil((float)f.size()/ncol);
    for(int r=0;r<nrow;r++){
        int c;
        for(c=r;c<f.size()-nrow;c+=nrow){
            printf("%s", f[c].c_str());
            for(int i=f[c].size();i<maxlen+2;i++) putchar(' ');
        }
        printf("%s", f[c].c_str());
        for(int i=f[c].size();i<maxlen;i++) putchar(' ');
        putchar('\n');
    }
}
bool cmp(string a, string b){
    if(maxlen<a.size()) maxlen = a.size();
    if(maxlen<b.size()) maxlen = b.size();
    return a<b;
}
int main(){
#ifdef LOCAL
    freopen("5-8.in", "r", stdin);
    freopen("5-8.out", "w", stdout);
#endif
    int n;
    while(scanf("%d%*c", &n)==1){
        F.clear(); maxlen = 0;
        while(n--){
            scanf("%s%*c", ibuff);
            F.push_back(string(ibuff));
        }
        sort(F.begin(), F.end(), cmp);
        printF(F);
    }

}