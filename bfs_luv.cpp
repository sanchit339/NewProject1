
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

vector<int>g[N];
int vis[N];
int level[N]; 

void bfs(int source){
    queue<int>q;
    q.push(source);
    // mark the source visited
    vis[source] = 1;
    // empty the queue
    while(!q.empty){
        // if not visited push in queue
        int curr_v = q.front();
        q,pop();
        cout << curr_v << " " ;
        for(int child : g[curr_v]){
            if(!vis[curr_v]){
                q.push(child);
                vis[child] = 1;
                level[child] = level[curr_v] + 1;
            }
        }
    }
    cout << endl;
}

int main(){
    
    int n ; cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x , y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(1);

    for(int i = 1 ; i <= n ; ++i){
        cout << i << " : "  << level[i] << endl;
    } 

    return 0;
}