#include<cstdio>
#include<queue>
#include<map>
#define maxn 1010
using namespace std;

map<int,int> e2t;
queue<int> tq, eq[maxn];

int main(){
#ifdef LOCAL
    freopen("5-6.in", "r", stdin);
    freopen("5-6.out", "w", stdout);
#endif
    int tn, en, elem, team, scen=0; char comm;
    while((scanf("%d", &tn)==1) && tn){
        printf("Scenario #%d\n", ++scen);
        e2t.clear();queue<int>().swap(tq);for(int i=0;i<tn;i++){queue<int>().swap(eq[i]);}
        for(int i=0;i<tn;i++){
            scanf("%d", &en);
            while(en--){
                scanf("%d", &elem);
                e2t[elem] = i;
            }
            while(getchar()!='\n');
        }
        while((comm=getchar())!='S'){
            switch(comm){
                case 'E':
                    while(getchar()!=' ');
                    scanf("%d", &elem);
                    team = e2t[elem];
                    if(eq[team].empty()) tq.push(team);
                    eq[team].push(elem);
                    break;
                case 'D':
                    if(tq.empty()) break;
                    printf("%d\n", eq[tq.front()].front()); eq[tq.front()].pop();
                    if(eq[tq.front()].empty()) tq.pop();
            }
            while(getchar()!='\n');
        }
        while(getchar()!='\n'); 
        putchar('\n');

    }
    return 0;
}