#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
#ifdef LOCAL
    freopen("5-1.in", "r", stdin);
#endif
    int n,q,count=0,tmp,idx; vector<int> a;
    while((scanf("%d%d", &n, &q)==2) && (n|q)){
        printf("CASE# %d:\n", ++count);
        a.clear();
        while(n--) {scanf("%d", &tmp);a.push_back(tmp);}
        sort(a.begin(), a.end());
        while(q--){
            scanf("%d", &tmp);
            if(a[idx=lower_bound(a.begin(), a.end(),tmp)-a.begin()]==tmp)
                printf("%d found at %d\n", tmp, idx+1);
            else printf("%d not found\n", tmp);
        }
    }
    return 0;
}