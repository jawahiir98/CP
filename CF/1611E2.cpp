/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';

int main()
{
    int T; cin>> T;
    while(T--)
    {
        int N,K; cin>> N >> K;
        vector <int> g[N + 1],dis(N + 1, -1);
        queue <int> q;
        for(int i = 0;i < K;i++){
            int x; cin>> x;
            dis[x] = 0;
            q.push(x);
        }
        for(int i = 0;i < N - 1;i++){
            int u,v; cin>> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int v : g[u]) if(dis[v] == -1)
            {
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
        function <bool(int, int, int)> dfs = [&](int node,int par,int cur)
        {
            if(node != 1 && g[node].size() == 1) return true;
            bool can = false;
            for(int v : g[node]) if(v != par && dis[v] > cur + 1)
            {
                can |= dfs(v, node, cur + 1);
            }
            return can;
        };
        function <int(int, int, int)> dfs2 = [&](int node,int par,int cur)
        {
            int ret = 0;
            if(dis[node] <= cur) return 1;
            for(auto v : g[node]) if(v != par)
            {
                ret += dfs2(v, node, cur + 1);
            }
            return ret;
        };
        bool ok = dfs(1, 1, 0);
        if(ok){
            cout<< -1 << nl;
            continue;
        }
        else{
            cout<< dfs2(1, 1, 0) << nl;
        }
    }
}

