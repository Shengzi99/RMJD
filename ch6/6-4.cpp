#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;

char s[maxn];
int len, next[maxn], last,  cur;

void insert(char c){
    s[++len] = c;
    next[len] = next[cur]; next[cur] = len;
    cur = len; if(next[cur]==-1) last = cur;
    return;
}
void prints(){
    int i=0;
    while(~(i=next[i])) putchar(s[i]);
    return;
}

int main(){
#ifdef LOCAL
    freopen("6-4.in","r",stdin);
    freopen("6-4.out", "w", stdout);
#endif
    int ch=0;
    while(ch!=EOF){
        memset(s, 0, sizeof(s)); memset(next, 0, sizeof(next)); 
        len=0; last=cur=0; next[0]=-1;
        while((ch=getchar())!='\n' && ch!=EOF){
            if(ch=='[') cur=0;
            else if(ch==']') cur=last;
            else insert(ch);
        }
        prints();
        if(ch!=EOF) putchar('\n');
    }
    return 0;
}