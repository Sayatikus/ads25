#include <iostream>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> st, vis, par;
int cy_u=-1, cy_v=-1;
bool found=false;

void dfs(int v){
    vis[v]=1;
    for(int u:g[v]){
        if(found) return;
        if(vis[u]==0){
            par[u]=v;
            dfs(u);
        }else if(vis[u]==1){
            cy_u=v; cy_v=u;
            found=true;
            return;
        }
    }
    vis[v]=2;
}

bool check_dag(int bx,int by){
    vector<int> vv(n+1,0);
    function<bool(int)> go=[&](int v){
        vv[v]=1;
        for(int u:g[v]){
            if((v==bx && u==by)) continue;
            if(vv[u]==1) return false;
            if(vv[u]==0){
                if(!go(u)) return false;
            }
        }
        vv[v]=2;
        return true;
    };
    for(int i=1;i<=n;i++){
        if(vv[i]==0){
            if(!go(i)) return false;
        }
    }
    return true;
}

int main(){
    cin>>n>>m;
    g.assign(n+1,{});
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        g[x].push_back(y);
    }
    vis.assign(n+1,0);
    par.assign(n+1,-1);

    for(int i=1;i<=n;i++){
        if(!vis[i] && !found) dfs(i);
    }

    if(!found){
        cout<<"YES";
        return 0;
    }

    vector<pair<int,int>> cyc;
    int x=cy_u, y=cy_v;
    cyc.push_back({x,y});
    while(x!=y){
        cyc.push_back({par[x],x});
        x=par[x];
    }

    for(auto &e:cyc){
        if(check_dag(e.first,e.second)){
            cout<<"YES";
            return 0;
        }
    }

    cout<<"NO";
}