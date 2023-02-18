#include<cstdio>
#include<cstring>
#include<cctype>
#define MAX(a,b) ((a)>(b)?(a):(b))

int V[26], N;
int DEG[26];
int E[26][26];
int tmp[8], ans[8], BW_t[8], BW_a;
bool readG(){
    memset(E, 0, sizeof(E)); memset(V, 0, sizeof(V)); N=0; memset(DEG, 0, sizeof(DEG));
    int ch; char cur_v; int status=0;
    while((ch=getchar())!='\n' && ch!=EOF){
        if(ch=='#') return false;
        if(isupper(ch)){
            V[ch-'A'] = 1;
            if(status){
                if(!E[cur_v-'A'][ch-'A']) {DEG[cur_v-'A']++; DEG[ch-'A']++;}
                E[cur_v-'A'][ch-'A']=E[ch-'A'][cur_v-'A']= 1;
            }
            else cur_v = ch;
        }
        if(ch==':') status = 1;
        if(ch==';') status = 0;
    }
    for(int i=0;i<26;i++) {N+=V[i];}
    return true;
}
void dfs(int cur){
    if(cur==N && BW_t[N-1]<BW_a) {memcpy(ans, tmp, sizeof(tmp)); BW_a = BW_t[N-1];}
    for(int i=0;i<26;i++){
        if(V[i]){
            bool uniq=true;
            for(int j=0;j<cur;j++) if(tmp[j]==i) {uniq=false;break;}
            if(!uniq) continue;
            bool bwok=true; BW_t[cur]=cur?BW_t[cur-1]:0; int preNum=0;
            for(int j=0;j<cur;j++) if(E[i][tmp[j]]){
                preNum++;
                if((cur-j)>=BW_a) bwok=false;
                else BW_t[cur]= MAX(BW_t[cur], (cur-j));
            }
            if(!bwok) continue;
            if((DEG[i]-preNum)>=BW_a ) continue;
            tmp[cur] = i;
            dfs(cur+1);
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("7-6.in", "r", stdin);
#endif
    while(readG()){
        memset(tmp, 0, sizeof(tmp));memset(ans, 0, sizeof(ans));memset(BW_t, 0, sizeof(BW_t));BW_a=N;
        dfs(0);
        for(int i=0;i<N;i++) {if(i) putchar(' '); putchar('A' + ans[i]);} printf(" -> %d\n", BW_a);
    }
    return 0;
}