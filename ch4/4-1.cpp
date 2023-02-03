#include<cstdio>
#include<cstring>
#include<cstdlib>

int a[26];
int b[26];

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
#ifdef LOCAL
    freopen("4-1.in", "r", stdin);
#endif
    char ch;
    while((ch=getchar())!=EOF){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        a[ch-'A'] ++;
        while ((ch=getchar())!='\n') a[ch-'A'] ++;
        while ((ch=getchar())!='\n' && ch!=EOF) b[ch-'A'] ++;

        qsort(a, 26, sizeof(int), &cmp);
        qsort(b, 26, sizeof(int), &cmp);

        int yes=1;
        for(int i=0;i<26 && yes;i++) if(a[i]!=b[i]) yes=0;
        printf("%s\n", yes?"YES":"NO");
    }

    return 0;
}