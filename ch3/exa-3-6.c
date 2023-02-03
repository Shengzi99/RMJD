#include<stdio.h>
#include<string.h>
#define NEXT(I, M) (I+1)%M
#define PUSH(S, T, E) S[++T] = E
#define mmax 105

char buff[mmax];
int s_a[mmax];
int s_b[mmax];

void swap_stack(int **s1, int **s2, int *t1, int *t2){
    int *tmp_s = *s1;
    *s1 = *s2;
    *s2 = tmp_s;

    int tmp_t = *t1;
    *t1 = *t2;
    *t2 = tmp_t;
}

int main(){

#ifdef LOCAL
    freopen("exa-3-6.in", "r", stdin);
#endif
    int n, m;
    int *s_cur = s_a;
    int *s_nxt = s_b;
    int t_cur, t_nxt;

    scanf("%d", &n);
    while(n--){
        scanf("%s", buff);
        m = strlen(buff);

        t_cur = -1;
        t_nxt = -1;
        for(int i=0;i<m;i++){
            PUSH(s_cur, t_cur, i);
        }
        
        int offset = -1;
        while(t_cur){
            char nxt_min = 'T';
            t_nxt = -1;
            for(int i=0;i<=t_cur;i++){
                if(buff[NEXT(s_cur[i], m)]>nxt_min) continue;
                if(buff[NEXT(s_cur[i], m)]<nxt_min){
                    t_nxt = -1;
                    nxt_min = buff[NEXT(s_cur[i], m)];
                }
                PUSH(s_nxt, t_nxt, NEXT(s_cur[i], m));
            }
            swap_stack(&s_cur, &s_nxt, &t_cur, &t_nxt);  
            offset++;
            if((t_cur+1)*(offset+1)==m) break;       
        }
        int start = (s_cur[0]-offset+m) % m;
        for(int i=0;i<m;i++,start=NEXT(start, m)){
            printf("%c", buff[start]);
        }
        printf("\n");
    }
}