#include<cstdio>
#include<cstring>
#include<queue>
#include<deque>
#include<string>
using namespace std;
typedef queue<string> Proc;

int vars[26];
int lock;
int at, pt, lt, ut, et, q;
Proc proc[10];
queue<int> susp;
deque<int> ready;

void exec(int pid){
    string stat; int cur_q = q;
    while(cur_q>0){
        stat = proc[pid].front();
        if(stat == "end") {proc[pid].pop(); return;}
        if(stat[2]=='='){
            int num; sscanf(stat.c_str(), "%*c%*c%*c%d", &num);
            vars[stat[0]-'a'] = num; cur_q-=at; proc[pid].pop(); continue;
        }
        switch(stat[0]){
            case 'p':
                printf("%d: %d\n", pid+1, vars[stat[6]-'a']); 
                cur_q-=pt; proc[pid].pop(); break;
            case 'l':
                if(lock) {susp.push(pid); return;}
                else lock = 1; 
                cur_q-=lt; proc[pid].pop(); break;
            case 'u': 
                lock=0; 
                if(susp.size()) {ready.push_front(susp.front()); susp.pop();}
                cur_q-=ut; proc[pid].pop();
        }
    }
    ready.push_back(pid);
}

int main(){
#ifdef LOCAL
    freopen("6-1.in", "r", stdin);
    freopen("6-1.out", "w", stdout);
#endif
    int cnum; scanf("%d", &cnum);
    int pn, pid; char sbuff[10];
    while(cnum--){
        memset(vars, 0, sizeof(vars)); lock=0; queue<int>().swap(susp); ready.clear();
        scanf("%d%d%d%d%d%d%d%*c", &pn, &at, &pt, &lt, &ut, &et, &q);
        for(int i=0;i<pn;i++){
            while(scanf("%[^\n]%*c", sbuff)==1 && sbuff[2]!='d') {proc[i].push(string(sbuff));}
            proc[i].push("end");
            ready.push_back(i);
        }
        while(!ready.empty()){
            pid = ready.front(); ready.pop_front();
            exec(pid);
        }
        if(cnum) putchar('\n');
    }
    return 0;
}