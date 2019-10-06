#include <iostream>
using namespace std;
#include <cstring>
#include<vector>
int map[100][100];
bool visited[100];
int cost = 1<<30; // 
int n;
vector<int> ans;
bool finish(){
    for (int i = 0;i<n;++i){
        if (!visited[i])
            return false;
    }
    return true;
}
void DFS(int now, vector<int> l) {
    if (visited[now])
        return;
    visited[now] = true;
    if(finish()) {
        if(cost > l[l.size()-1]){
            cost = l[l.size()-1];
            ans = l;
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (map[now][i] != -1) {
            vector<int> t = l;
            if(!l.empty())
                t.push_back(map[now][i] + l[l.size()-1]);
            else
                t.push_back(map[now][i]);
            DFS(i, t);
        }
    }
    visited[now] = false;
}
int main(){
    int m,x,y;
    cin>> n>>m;
    memset(map,-1,sizeof(map));
    for(int i = 0; i < m; ++i){
        cin >> x>> y;
        map[y][x] = map[x][y] = 1<<i;
    }

    memset(visited, false ,sizeof(visited));
    vector<int> temp;
    DFS(0, temp);
    if (ans.size() == 0){
        cout << -1;
    } else {
        for (int i = 0;i < ans.size();++i){
            cout<< ans[i]<< endl;
        }
    }
}