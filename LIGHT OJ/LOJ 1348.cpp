/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int LOG = 15;
const int E = 3e4 + 10;
inline int nextint(){ int x; scanf("%d",&x); return x; }

int main()
{
    int T = nextint(),cs = 0;
    while(T--)
    {
        int N = nextint();
        vector <int> a(N),depth(N + 1, 0),cnt(N + 1, 0);
        for(int i = 0;i < N;i++) a[i] = nextint(),cnt[i] = a[i];
        vector <int> g[N];
        vector <vector<int>> up(N + 1, vector <int> (LOG, 0));
        for(int i = 0;i < N - 1;i++){
            int u,v;
            u = nextint();
            v = nextint();
            g[u].pb(v);
        }
        function <int(int)> dfs = [&](int x)
        {
            for(int v : g[x]){
                depth[v] = depth[x] + 1;
                up[v][0] = x;
                for(int i = 1;i < LOG;i++){
                    up[v][i] = up[up[v][i - 1]][i - 1];
                }
                cnt[x] += dfs(v);
            }
            return cnt[x];
        };
        cnt[0] = dfs(0);
        auto LCA = [&](int x,int y)
        {
            if(depth[x] < depth[y]) swap(x, y);
            int K = depth[y] - depth[x];
            for(int j = LOG - 1; j >= 0; j--) {
                if(K & (1 << j)) {
                    x = up[x][j]; // parent of a
                }
            }
            if(x == y) return x;
            for(int j = LOG - 1; j >= 0; j--) {
                if(up[x][j] != up[x][j]) {
                    x = up[x][j];
                    y = up[y][j];
                }
            }
            return up[x][0];
        };
        int Q = nextint();
        while(Q--)
        {
            int c = nextint();
            if(c == 0){
                int l = nextint(),r = nextint();
                int V = LCA(l, r);
                if(V == l || V == r){

                }

            }else{
                int pos = nextint(),val = nextint();
            }
        }
    }
}
