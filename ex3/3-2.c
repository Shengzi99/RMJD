#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define nmax 100

char buff[nmax];
int main(){
#ifdef LOCAL
    freopen("3-2.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    while(n--){
        scanf("%s", buff);
        int idx=0;
        int fac=0;
        double mass=0;
        double cur_m=0;
        while(1){
            if(isdigit(buff[idx])) fac = fac * 10 + (buff[idx]-'0');
            else{
                mass += (fac?fac:1)*cur_m;
                if(buff[idx]=='\0') break;

                fac = 0;
                switch (buff[idx])
                {
                case 'C':
                    cur_m = 12.01;break;
                case 'H':
                    cur_m = 1.008;break;
                case 'O':
                    cur_m = 16.00;break;
                case 'N':
                    cur_m = 14.01;break;
                }
            }
            idx++;
        }
        printf("%.3lf\n", mass);
    }

    return 0;
}