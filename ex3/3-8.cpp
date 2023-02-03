#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>

int last[30000];

int main(){
#ifdef LOCAL
    freopen("3-8.in", "r", stdin);
#endif
    int a, b;
    while(scanf("%d%d", &a, &b)==2){
        printf("%d/%d = %d.", a, b, a/b); a = a%b*10;
        memset(last, 0, sizeof(last));
        std::string ans = "";
        int pos = 0, loop=0;
        while(!last[a]){
            last[a] = ++pos;
            if(pos<51) ans.push_back((char)(a/b+'0'));
            a = a%b*10;
        }
        loop = pos-last[a]+1;
        ans.insert(pos-loop, "(");
        printf("%s%s)\n", ans.c_str(), pos>50?"...":"");
        printf("   %d = number of digits in repeating cycle\n\n", loop);
    }
}