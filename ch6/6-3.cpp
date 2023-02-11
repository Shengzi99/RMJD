#include<cstdio>
#include<cctype>
#include<stack>
#define R(x) ((x)/(1<<16))
#define C(x) ((x)&((1<<16)-1))
#define MULT(x,y) ((R(x)<<16)+C(y))
#define ELEN(x,y) (R(x)*C(x)*C(y))
using namespace std;

unsigned M[26];
stack<unsigned> mat;

int main(){
#ifdef LOCAL
    freopen("6-3.in", "r", stdin);
    freopen("6-3.out", "w", stdout);
#endif
    int n; scanf("%d%*c", &n);
    unsigned op1, op2, elen; char m=0;
    while(n--){
        m = getchar(); scanf("%d%d%*c", &op1, &op2);
        M[m-'A'] = (op1<<16)+op2;
    }
    int error=0, ok2print;
    while(m!=EOF){
        elen = 0; error = 0; ok2print=0;
        while( (m=getchar())!='\n' && m!=EOF ){
            ok2print = 1;
            if(error) continue;
            if(m == ')'){ 
                op2=mat.top(); mat.pop(); op1=mat.top(); mat.pop();
                if(C(op1) != R(op2)) error=1;
                else {mat.push(MULT(op1, op2)); elen+=ELEN(op1, op2);}
            }
            else if(isalpha(m)) mat.push(M[m-'A']);
        }
        if(ok2print){
            if(error) printf("error\n");
            else printf("%d\n", elen);
        }
    }
    return 0;
}