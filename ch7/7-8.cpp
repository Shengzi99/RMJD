#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<unordered_set>
#define MIN(A,B) ((A)<(B)?(A):(B))
#define ID(DATA) ((DATA[0]<<16)|(DATA[1]<<8)|DATA[2])
using namespace std;


struct Status{
    int data[3];
    int dist;
    Status(int a, int b, int c, int d){data[0]=a;data[1]=b;data[2]=c;dist=d;}
    bool operator< (const Status & b) const {return dist>b.dist;}
};

unordered_set<int> visited;
priority_queue<Status> PQ;
int capa[3],a,b,c,d,dres_min,dist_min; 

void bfs(){
    int new_data[3], new_dist, new_dres, delta; PQ.push(Status(0,0,c,0)); //visited.insert(ID(PQ.top().data));
    while(!PQ.empty()){
        visited.insert(ID(PQ.top().data));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==j) continue;
                memcpy(new_data, PQ.top().data, sizeof(new_data)); delta = MIN(new_data[i], capa[j]-new_data[j]);
                new_dist=PQ.top().dist+delta; 
                new_data[j]+=delta; new_data[i]-=delta;
                new_dres=d;
                for(int di=0;di<3;di++)if(d-new_data[di]>=0) new_dres=MIN(new_dres, d-new_data[di]);
                if(new_dres<dres_min) {dres_min=new_dres; dist_min=new_dist;}
                else if(new_dres==dres_min) dist_min=MIN(new_dist,dist_min);
                if(visited.count(ID(new_data))==0){
                    // visited.insert(ID(new_data)); //刘汝佳的写法
                    PQ.push(Status(new_data[0],new_data[1],new_data[2],new_dist));
                }
            }
        }
        // if(dres_min==0) return;
        PQ.pop();
    }
}
int main(){
#ifdef LOCAL
    freopen("7-8-c.in", "r", stdin);
    freopen("7-8.out", "w", stdout);
#endif
    int cnum; scanf("%d", &cnum);
    while(cnum--){
        scanf("%d%d%d%d", &a,&b,&c,&d);capa[0]=a;capa[1]=b;capa[2]=c;
        dres_min=d; dist_min=0; visited.clear(); priority_queue<Status>().swap(PQ);
        bfs();
        printf("%d %d\n", dist_min, d-dres_min);        
    }
    return 0;
}