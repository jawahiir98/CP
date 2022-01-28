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
const int MOS = 1e9 + 7;


vector <int> g[E],p(E),a(E);
vector <pair<int, int>> edge[E];
ll ans;
int N,M,cnt;
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
        cin>> M;
        for(int i = 0;i < M;i++){
            cin>> p[i];
        }
        queue <int> q;
        q.push(1);
        vector <int> dis(N + 1, 0),vis(N + 1, 0);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int v : g[u]){
                if(v == 1) continue;
                if(dis[v] == 0){
                    q.push(v);
                    dis[v] = dis[u] + 1;
                    if(cnt < M){
                        edge[u].pb({v, p[cnt]});
                        edge[v].pb({u, p[cnt++]});
                    }
                    else{
                        edge[u].pb({v, 1});
                        edge[v].pb({u, 1});
                    }
                }
            }
        }
        //for(int i = 0;i <= N;i++) dis[i] = 0;
        q.push(1);
        vis[1] = 1;
        while(!q.empty())
        {
            int u= q.front(); q.pop();
            for(auto [v, w] : edge[u]){
                if(vis[v] == 0){
                    q.push(v);
                    dis[v] = dis[v] + w;
                    vis[v] = 1;
                }
            }
        }
        for(int i = 1;i <= N;i++) cout<< dis[i] <<' ';
        cout<< nl;
        //cout<< ans << nl;
    }
}
