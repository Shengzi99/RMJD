#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int iDeg[26];
int oDeg[26];
int visit[26];
int E[26][26];

void dfs(int i){
    visit[i] = 1;
    for(int j=0;j<26;j++)
        if( (E[i][j]|E[j][i]) && !visit[j]) dfs(j);
}
bool is_degOk(){
    int oddV = 0;
    for(int i=0;i<26;i++){
        if(iDeg[i]!=oDeg[i]){
            if(abs(iDeg[i]-oDeg[i])==1) oddV++;
            else return false;
        }
        if(oddV>2) return false;
    }
    return true;
}
bool is_conn(){
    memset(visit, 0, sizeof(visit));
    int cc=0;
    for(int i=0;i<26;i++){
        if( (oDeg[i]|iDeg[i]) && !visit[i]) {dfs(i); cc++;}
    }
    if(cc>1) return false;
    return true;
}
int main(){
#ifdef LOCAL
    freopen("6-16.in", "r", stdin);
#endif
    int T, N; scanf("%d", &T); int ch, ch1, ch2;
    while(T--){
        memset(iDeg, 0, sizeof(iDeg)); memset(oDeg, 0, sizeof(oDeg)); memset(E, 0, sizeof(E));
        scanf("%d%*c", &N); 
        while(N--){
            ch1 = getchar()-'a'; ch=0;
            while( (ch = getchar())!='\n' && ch!=EOF) ch2 = ch;
            ch2 -= 'a';
            oDeg[ch1]++; iDeg[ch2]++; E[ch1][ch2]++;
        }
        // printf("(%d,%d) ", is_degOk(), is_conn());
        printf("%s\n", (is_degOk()&&is_conn())?"Ordering is possible.":"The door cannot be opened.");
    }
}