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

vector <ll> a,lazy(E * 4),tree(4 * E);
void propagate(int at,int L,int R)
{
    if(L != R){
        lazy[at * 2] = lazy[at * 2] + lazy[at];
        lazy[at * 2 + 1] = lazy[at * 2 + 1] + lazy[at];
    }
    tree[at] += (R - L + 1) * lazy[at];
    lazy[at] = 0;
}
void build(int at,int L,int R)
{
    if(L == R){tree[at] = a[L]; return; }
    int M = (L + R)/2;
    build(at * 2, L, M);
    build(at * 2 + 1, M + 1, R);
    tree[at] = tree[at * 2] + tree[at * 2 + 1];
}
void update(int at,int L,int R,int l,int r,ll val)
{
    if(lazy[at] != 0) propagate(at, L, R);
    if(L > r || R < l) return;
    if(L >= l and R <= r){
        if(L != R){
            lazy[at * 2] += val;
            lazy[at * 2 + 1] += val;
        }
        tree[at] += (R - L + 1) * val;
        return;
    }
    int M = (L + R)/2;
    update(at * 2, L, M, l, r, val);
    update(at * 2 + 1, M + 1, R, l, r, val);
    tree[at] = tree[at * 2] + tree[at * 2 + 1];
}
ll query(int at,int L,int R,int l,int r)
{
    if(lazy[at]) propagate(at, L, R);
    if(L > r || R < l) return 0;
    if(L >= l and R <= r) return tree[at];
    int M = (L + R)/2;
    ll x = query(at * 2, L, M, l, r);
    ll y = query(at * 2 + 1, M + 1, R, l, r);
    return x + y;
}
int main()
{
    int N,q; cin>> N >> q;
    a.resize(N + 1);
    for(int i = 1;i <= N;i++) cin>> a[i];
    build(1, 1, N);
    while(q--)
    {
        int op; cin>> op;
        if(op == 1){
            int l,r,val; cin>> l >> r >> val;
            update(1, 1, N, l, r, val);
        }
        else{
            int x; cin>> x;
            cout<< query(1, 1, N, x, x) << nl;
        }
    }
}
