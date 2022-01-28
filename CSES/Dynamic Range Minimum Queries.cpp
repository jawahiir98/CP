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

vector <ll> a,tree(E * 4);
void build(ll at,ll L,ll R)
{
    if(L == R) {tree[at] = a[L]; return; }
    int M = (L + R)/2;
    build(at * 2, L, M);
    build(at * 2 + 1, M + 1, R);
    tree[at] = min(tree[at * 2], tree[at * 2 + 1]);
}
ll query(ll at,ll L,ll R,ll l,ll r)
{
    if(L > r || R < l) return 1e18;
    if(L >= l && R <= r) return tree[at];
    int M = (L + R)/2;
    ll x = query(at * 2, L, M, l, r);
    ll y = query(at * 2 + 1, M + 1, R, l, r);
    return min(x, y);
}
void update(ll at,ll L,ll R,ll pos,ll val)
{
    if(pos < L || pos > R) return ;
    if(L == R){
        tree[at] = val;
        return;
    }
    ll M = (L + R)/2;
    update(at * 2, L, M, pos, val);
    update(at *2 + 1, M + 1, R, pos, val);
    tree[at] = min(tree[at * 2], tree[at * 2 + 1]);
}
int main()
{
    ll N,Q; cin>> N >> Q;
    a.resize(N + 1);
    for(int i = 1;i <= N;i++) cin>> a[i];
    build(1, 1, N);
    while(Q--)
    {
        ll op; cin>> op;
        if(op == 1){
            ll pos,val; cin>> pos >> val;
            update(1, 1, N, pos, val);
        }else{
            ll a,b; cin>> a >> b;
            cout<< query(1, 1, N, a, b) << nl;
        }
    }
}
