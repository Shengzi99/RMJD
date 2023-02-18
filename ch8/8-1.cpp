#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> V;

int main(){
#ifdef LOCAL
    freopen("8-1.in", "r", stdin);
#endif
    char ch=0; int tmp;
    while(scanf("%d%c", &tmp, &ch)==2){
        V.clear(); V.push_back(0); V.push_back(tmp); 
        if(ch!='\n'){
            while(scanf("%d%c", &tmp, &ch)==2 && ch!='\n') V.push_back(tmp);
            V.push_back(tmp);
        }
        reverse(V.begin()+1, V.end());
        for(auto it=V.rbegin();it!=V.rend()-1;it++) printf("%d%c", *it, (V.rend()-it-2)?' ':'\n');
        int i=0,n=V.size()-1, pos;
        while(++i<=n){
            pos = max_element(V.begin()+i, V.end())-V.begin();
            if(pos==i) continue;
            if(pos!=n) {reverse(V.begin()+pos, V.end()); printf("%d ", pos);}
            reverse(V.begin()+i,V.end()); printf("%d ", i);
        }
        printf("0\n");
    }
    return 0;
}