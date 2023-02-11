#include<cstdio>
#include<set>
#include<unordered_set>
#include<queue>
using namespace std;

#ifdef USE_PQ

priority_queue<long long,vector<long long>,greater<long long> > pq;
unordered_set<long long> S;
int main(){
    int count=1500; long long tmp; pq.push(1); S.insert(1); int fac[3]={2,3,5};
    while(--count){
        for(int i=0;i<3;i++){
            tmp = pq.top()*fac[i];
            if(!S.count(tmp)) {S.insert(tmp); pq.push(tmp);}
        }
        pq.pop();
    }
    printf("The 1500'th ugly number is %lld.\n", pq.top());
    return 0;
}

#else

set<long long> S;
int main(){
    long long count=1500; S.insert(1);
    set<long long>::iterator it = S.begin();
    while(--count){
        S.insert(*it*2); S.insert(*it*3); S.insert(*it*5);
        it++;
    }
    printf("The 1500'th ugly number is %lld.\n", *it);
    return 0;
}

#endif