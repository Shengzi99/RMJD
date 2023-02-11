#include<cctype>
#include<cstdio>
#include<string>
#include<set>
using namespace std;

int main(){
    set<string> S; char ch; string str="";
    while((ch=getchar())!=EOF){
        if(isalpha(ch)) str.push_back(tolower(ch));
        else if(str.length()) {S.insert(str); str="";}
    }
    for(auto it=S.begin();it!=S.end();it++) printf("%s\n", it->c_str());
    return 0;
}