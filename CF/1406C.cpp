/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 1e5 + 10;

vector <int> g[E],sz(E);
int N;
void dfs(int u,int p)
{
    sz[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
int centroid(int u,int p)
{
    int mx = -1,id = -1;
    for(auto v : g[u]){
        if(v == p) continue;
        if(mx < sz[v]){
            mx = sz[v];
            id = v;
        }
    }
    if(mx > N / 2) return centroid(id, u);
    else return u;
}
int main()
{
    int T; cin>> T;
    while(T--)
    {
        cin>> N;
        for(int i = 0;i < N - 1;i++){
            int u,v; cin>> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(1, 0);
        int u = centroid(1, 0);
        dfs(u, 0);
        int mx = 0,id;
        //cout<< u << nl;
        for(int v : g[u]){
            if(mx < sz[v]){
                mx = sz[v];
                id = v;
            }
        }
        int w = id, v;
        if(sz[w] * 2 == N){
            for(int x : g[w]){
                if(x != u){
                    v = x;
                }
            }
            cout<< w << ' ' << v << nl;
            cout<< v << ' ' << u << nl;
        }
        else{
            cout<< u << ' ' << w << nl;
            cout<< u << ' ' << w << nl;
        }
        for(int i = 1;i <= N;i++) g[i].clear(),sz[i] = 0;
    }
}
