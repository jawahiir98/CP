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
inline int nextint(){ int x; scanf("%d",&x); return x; }

vector <int> a,tree(E * 4),bree(E * 4);
void build(int at,int L,int R)
{
    if(L == R){tree[at] = a[L],bree[at] = a[L]; return;}
    int M = (L + R)/2;
    build(at * 2,L ,M);
    build(at * 2 + 1,M + 1 ,R);
    tree[at] = max(tree[at * 2], tree[at * 2 + 1]);
    bree[at] = min(bree[at * 2], bree[at * 2 + 1]);
}
int query(int at,int L,int R,int l,int r)
{
    if(L > r || R < l) return -1;
    if(L >= l && R <= r) return tree[at];
    int M = (L + R)/2;
    int x = query(at * 2, L, M, l, r);
    int y = query(at * 2 + 1, M + 1, R, l, r);
    return max(x , y);
}
int query2(int at,int L,int R,int l,int r)
{
    if(L > r || R < l) return 1e9;
    if(L >= l && R <= r) return bree[at];
    int M = (L + R)/2;
    int x = query2(at * 2, L, M, l, r);
    int y = query2(at * 2 + 1,M + 1, R, l, r);
    return min(x, y);
}
int main()
{
    int cs = 0,T = nextint();
    while(T--)
    {
        int N = nextint(),D = nextint();
        a.resize(N + 1);
        for(int i = 1;i <= N;i++) a[i] = nextint();
        build(1, 1, N);
        int mx = 0;
        for(int i = 1;i <= N - D;i++){
            mx = max(mx, abs(query(1, 1, N, i, i + D - 1) - query2(1, 1, N, i, i + D - 1)));
            //cout<< query(1, 1, N, i, i + D - 1) << ' ' << query2(1, 1, N, i, i + D - 1) << nl;
        }
        printf("Case %d: %d\n", ++cs, mx);
    }
}
