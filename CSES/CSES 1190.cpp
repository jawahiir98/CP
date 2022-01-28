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

vector <ll> tree(4 * E),a;
void build(int at,int L,int R)
{
    if(L == R){
        tree[at] = a[L];
        return;
    }
    int M = (L + R)/2;
    build(at * 2, L, M);
    build(at * 2 + 1, M + 1, R);
    tree[at] = max(tree[at * 2] + tree[at * 2 + 1], max(tree[at * 2], tree[at * 2 + 1]));
}
void update(int at,int L,int R,int pos,ll val)
{
    if(pos < L or pos > R) return;
    if(L == R)
    {
        tree[at] = val;
        return;
    }
    int M = (L + R)/2;
    update(at * 2, L, M, pos, val);
    update(at * 2 + 1, M + 1, R, pos, val);
    tree[at] = max(tree[at * 2] + tree[at * 2+ 1], max(tree[at * 2], tree[at * 2 + 1]));
}
ll query(int at,int L,int R,int l,int r)
{
    if(L > r || R < l) return 0LL;
    if(L >= l and R <= r) return tree[at];
    int M = (L + R)/2;
    ll x = query(at * 2, L, M, l, r);
    ll y = query(at * 2 + 1, M + 1, R, l, r);
    return max(x, y);
}
int main()
{
    int N,Q; cin>> N >> Q;
    a.resize(N + 1);
    for(int i = 1;i <= N;i++) cin>> a[i];
    build(1, 1, N);
    while(Q--)
    {
        int pos,val; cin>> pos >> val;
        update(1, 1, N, pos, val);
        cout<< query(1, 1, N, 1, N) << nl;+
    }
}
