#include<cstdio>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

stack<int> SS;
map<set<int>, int> S2I;
vector<set<int>> I2S;

int ID(set<int> s){
    if(S2I.count(s)) return S2I[s];
    I2S.push_back(s); return S2I[s] = I2S.size()-1;
}
int main(){
#ifdef LOCAL
    freopen("5-5.in", "r", stdin);
    freopen("5-6.out", "w", stdout);
#endif
    int t,n; char comm; set<int> ta,tb,tc;
    scanf("%d", &t);
    while(t--){
        stack<int>().swap(SS);S2I.clear();I2S.clear();ID(set<int>());
        scanf("%d%*c", &n);
        while(n--){
            comm = getchar();
            switch(comm){
                case 'P': SS.push(0);break;
                case 'D': SS.push(SS.top());break;
                case 'U': case 'I': case 'A':
                    tc.clear(); ta=I2S[SS.top()];SS.pop(); tb=I2S[SS.top()];SS.pop();
                    if(comm=='U') set_union(ta.begin(),ta.end(),tb.begin(),tb.end(),inserter(tc,tc.begin()));                    
                    else if(comm=='I') set_intersection(ta.begin(),ta.end(),tb.begin(),tb.end(),inserter(tc,tc.begin()));
                    else (tc=tb).insert(ID(ta));
                    SS.push(ID(tc));break;
            }
            printf("%lu\n", I2S[SS.top()].size());
            while((comm=getchar())!='\n' && comm!=EOF);
        }
        printf("***\n");
    }
}