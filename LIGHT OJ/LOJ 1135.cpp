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

vector <ll> lazy(4 * E);
vector <array<ll, 4>> tree(4 * E);
void propagate(int at,int L,int R)
{
    if(L != R){
        lazy[at * 2] = (lazy[at * 2] + lazy[at]) % 3;
        lazy[at * 2 + 1] = (lazy[at * 2 + 1] + lazy[at]) % 3;
    }
    if(lazy[at] == 1){
        tree[at][2] = tree[at][1];
        tree[at][1] = tree[at][0];
        tree[at][0] = (R - L + 1) - tree[at][1] - tree[at][2];
    }
    if(lazy[at] == 2){
        tree[at][1] = tree[at][2];
        tree[at][2] = tree[at][0];
        tree[at][0] = (R - L + 1) - tree[at][1] - tree[at][2];
    }
    lazy[at] = 0;
}
void build(int at,int L,int R)
{
    tree[at][0] = (R - L + 1);
    tree[at][1] = tree[at][2] = lazy[at] = 0;
    if(L == R)
    {
        tree[at][0] = 1;
        return;
    }
    int M = (L + R)/2;
    build(at * 2, L, M);
    build(at * 2 + 1, M + 1, R);
}
void update(int at,int L,int R,int l,int r)
{
    if(lazy[at]) propagate(at, L, R);
    if(L > r || R < l) return;
    if(L >= l && R <= r){
        if(L != R)
        {
            lazy[at * 2] = (lazy[at * 2] + lazy[at] + 1) % 3;
            lazy[at * 2 + 1] = (lazy[at * 2 + 1] + lazy[at] + 1) % 3;
        }
        tree[at][2] = tree[at][1];
        tree[at][1] = tree[at][0];
        tree[at][0] = (R - L + 1) - tree[at][1] - tree[at][2];
        return;
    }
    int M = (L + R)/2;
    update(at * 2, L, M, l, r);
    update(at * 2 + 1, M + 1, R, l, r);
    for(int j = 0;j < 3;j++) tree[at][j] = tree[at * 2][j] + tree[at * 2 + 1][j];
}
ll query(int at,int L,int R,int l,int r)
{
    if(lazy[at]) propagate(at, L, R);
    if(L > r || R < l) return 0;
    if(L >= l && R <= r) return tree[at][0];
    int M = (L + R)/2;
    ll x = query(at * 2, L, M, l, r);
    ll y = query(at * 2 + 1, M + 1, R, l, r);
    for(int j = 0;j < 3;j++) tree[at][j] = (tree[at * 2][j] + tree[at * 2 + 1][j]);
    return x + y;
}
int main()
{
    int T = nextint(),cs = 0;
    while(T--)
    {
        int N = nextint(),q = nextint();
        build(1, 0, N - 1);
        printf("Case %d:\n", ++cs);
        while(q--)
        {
            int op, x, y; scanf("%d%d%d", &op, &x, &y);
            if(!op){
                update(1, 0, N - 1, x, y);
            }else{
                printf("%lld\n", query(1, 0, N - 1, x, y));
            }
        }
    }
}
