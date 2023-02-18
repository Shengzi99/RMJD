#include<cstdio>
#include<cstring>
#define ID(N,P) (2*(N-'A')+((P=='+')?1:0))
#define NEG_ID(N,P) (ID(N,P)^1)

char sBuff[9];
int V[52];
int E[52][52];

void dfs(int i, bool &DAG){
    if(!DAG) return;
    V[i] = 2;
    for(int j=0;j<52;j++)
        if(E[i][j]){
            if(V[j]==2) DAG = false;
            if(V[j]==1) dfs(j, DAG);
        }
    V[i] = 3;
}
bool is_DAG(){
    bool DAG = true;
    for(int i=0;i<52;i++) if(V[i]==1) dfs(i, DAG);
    return DAG;
}
int main(){
#ifdef LOCAL
    freopen("6-19.in", "r", stdin);
    freopen("6-19.out", "w", stdout);
#endif
    int n;
    while(scanf("%d%*c", &n)==1){
        memset(E, 0, sizeof(E)); memset(V, 0, sizeof(V));
        while(n--){
            scanf("%s", sBuff);
            for(int i=0;i<8;i+=2)
                for(int j=0;j<8;j+=2)
                    if( (i!=j) && (sBuff[i]!='0') && (sBuff[j]!='0')){
                        V[ID(sBuff[i],sBuff[i+1])]=V[NEG_ID(sBuff[j],sBuff[j+1])]=1;
                        E[ID(sBuff[i],sBuff[i+1])][NEG_ID(sBuff[j],sBuff[j+1])]=1;
                    }
        }
        printf("%s\n", is_DAG()?"bounded":"unbounded");
    }
}