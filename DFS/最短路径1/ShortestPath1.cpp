#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct Node{
    int e, l, co;
    Node(int ee=1, int ll=0,int cc=0) {
        e = ee; l = ll; co = cc;
    }
};
vector<Node> v[1000];
int len = 1<<30;
int cost;
int s,t;
bool visited[1000];
void DFS(int now, int path,int c){
    if (visited[now])
        return;
    if (now == t) {
        if (path < len) {
            len = path;
            cost = c;
        }
        return;
    }
    visited[now] = true;
    for (int i = 0;i < v[now].size();++i){
        if (path+v[now][i].l < len)
            DFS(v[now][i].e, path+v[now][i].l, c+v[now][i].co);
    }
    visited[now] = false;
}

int main(){
    int n,m;
    int first = 1;
    while (cin>> n>> m && n) {
        if(first == 1) {
            first = 0;
        } else {
            cout<<endl;
        }
        for (int i=0; i < n; ++i) {
            v[i].clear();
        }
        len = 1<<30;
        memset(visited, false, sizeof(visited));
        int b,e,l,c;
        for(int i=0;i<m;++i) {
            cin>> b>> e>> l>> c;
            v[b-1].push_back(Node(e-1, l ,c));
            v[e-1].push_back(Node(b-1, l, c));
        }
        cin>>s >> t;
        s-=1; t-=1;
        DFS(s, 0, 0);
        cout << len <<" "<< cost;
    }
}