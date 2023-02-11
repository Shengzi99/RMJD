#include<cstdio>
#include<queue>
using namespace std;
#define TREE

#ifdef TREE

struct Node{
    bool inited;
    int val;
    Node* lc;
    Node* rc;
    Node():inited(false),val(-1),lc(NULL),rc(NULL){}
};
char nPos[300]; 
Node* root; bool error;

Node* addNode(int v, char *s){
    Node* cur = root; int i=0;
    while(s[i]!=')'){
        switch(s[i]){
            case 'L': 
                if(!cur->lc) cur->lc = new Node();
                cur = cur->lc;
                break;
            case 'R':
                if(!cur->rc) cur->rc = new Node();
                cur = cur->rc;
        }
        i++;
    }
    if(cur->inited) error = true;
    else {cur->val = v; cur->inited=true;}
    return cur;
}
void delTree(Node* r){
    if(!r) return;
    if(r->lc) delTree(r->lc);
    if(r->rc) delTree(r->rc);
    delete r;
}
void BFS(Node* r, void (*visit)(Node*, bool last)){
    if(!r) return;
    queue<Node*> Q;
    Q.push(r);
    while(!Q.empty()){
        if(Q.front()->lc) Q.push(Q.front()->lc);
        if(Q.front()->rc) Q.push(Q.front()->rc);
        visit(Q.front(), !(Q.size()-1)); Q.pop();
    }
}
void visit_print(Node* a, bool last){
    printf("%d", a->val); if(!last) putchar(' ');
    return;
}
void visit_check(Node* a, bool last){
    if(!a->inited) error = true;
    return;
}

int main(){
#ifdef LOCAL
    freopen("6-6.in", "r", stdin);
#endif
    int v; char ch;
    while(ch!=EOF){
        delTree(root); root = new Node(); error = false;
        while(scanf("(%d,%[^(]", &v, nPos)==2) addNode(v, nPos);
        while((ch=getchar())!='\n' && ch!=EOF); 
        if(!(root->lc) && !(root->rc) && !root->inited) break;
        BFS(root, visit_check);
        if(error) {printf("not complete\n"); continue;}
        BFS(root, visit_print); putchar('\n');
    }
    return 0;
}


#endif