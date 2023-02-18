#include<cstdio>

bool eq;
int solve(){
    int wl, dl, wr, dr;
    scanf("%d%d%d%d", &wl, &dl, &wr, &dr);
    if(!wl) wl = solve();
    if(!wr) wr = solve();
    if( (wl*dl)!=(wr*dr) ) eq = false;
    return wl+wr; 
}

int main(){
#ifdef LOCAL
    freopen("6-9.in", "r", stdin);
    freopen("6-9.out", "w", stdout);
#endif
    int n; scanf("%d%*c%*c", &n);
    while(n--){
        eq = true;
        solve();
        printf("%s\n", eq?"YES":"NO");
        if(n) putchar('\n');
    }

    return 0;
}