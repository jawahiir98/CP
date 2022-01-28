/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 2e5 + 10;

struct Edge
{
    int u,v,w,t;
    bool operator < (const Edge &A) const{
        return w < A.w;
    }
};
vector <int> par,sz;
vector <Edge> edges;
int Find(int r)
{
    if(par[r] == r) return r;
    return par[r] = Find(par[r]);
}
void Union(int a,int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u != v)
    {
        if(sz[u] > sz[v]){
            swap(u, v);
        }
        sz[v] += sz[u];
        par[u] = v;
    }
}
int main()
{
    int N,M,Q; cin>> N >> M >> Q;
    par.resize(N  +1, 0);
    sz.resize(N + 1, 1);
    iota(par.begin(), par.end(), 0);
    for(int i = 0;i < M;i++){
        int u,v,w,c = -1; cin>> u >> v >> w;
        edges.pb({u, v, w, c});
    }
    for(int i = 0;i < Q;i++){
        int u,v,w,c = i; cin>> u >> v >> w;
        edges.pb({u, v, w, c});
    }
    sort(edges.begin(), edges.end());
    vector <bool> ans(Q, 0);
    for(auto [u, v, w, c] : edges)
    {
        int U = Find(u);
        int V = Find(v);
        if(U != V){
            if(c != -1) ans[c] = 1;
            else Union(u, v);
        }
    }
    for(int i = 0;i < Q;i++) cout<<(ans[i] ? "Yes" : "No") << nl;
}
