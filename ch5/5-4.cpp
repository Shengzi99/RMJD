#include<cstdio>
#include<cctype>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

map<string,vector<string>> cnt;
vector<string> ans;
string sorted(const string s){
    string ret = s;
    transform(ret.begin(),ret.end(),ret.begin(),::toupper);
    sort(ret.begin(), ret.end());
    return ret;
}
int main(){
    char ch; string tmp="";
    while((ch=getchar())!='#'){
        if(isalpha(ch)) tmp.push_back(ch);
        else if(tmp.size()) {
            string stmp = sorted(tmp);
            if(!cnt.count(stmp)) cnt[stmp]={};
            cnt[stmp].push_back(tmp);
            tmp = "";
        }
    }
    for(auto it=cnt.begin();it!=cnt.end();it++)
        if(it->second.size()==1) ans.push_back(it->second[0]);
    sort(ans.begin(),ans.end());
    for(auto it=ans.begin();it!=ans.end();it++) printf("%s\n", it->c_str());

    return 0;
}