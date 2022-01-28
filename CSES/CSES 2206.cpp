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

vector <ll> tree(4 * E),bree(4 * E),a;
void build_R(int at,int L,int R)
{
    if(L == R){tree[at] = a[L] + L; return; }
    int M = (L + R)/2;
    build_R(at * 2, L, M);
    build_R(at * 2 + 1, M + 1, R);
    tree[at] = min(tree[at * 2], tree[at * 2 + 1]);
}
void build_L(int at,int L,int R)
{
    if(L == R){bree[at] = a[L] - L; return; }
    int M = (L + R)/2;
    build_L(at * 2, L, M);
    build_L(at * 2 + 1, M + 1, R);
    bree[at] = min(bree[at * 2], bree[at * 2 + 1]);
}
ll query_L(int at,int L,int R,int l,int r )
{
    if(R < l || L > r) return 1e9 + 10;
    if(L >= l and R <= r) return bree[at];
    int M = (L + R)/2;
    ll x = query_L(at * 2, L, M, l, r);
    ll y = query_L(at * 2 + 1, M + 1, R, l, r);
    return min(x, y);
}
ll query_R(int at,int L,int R,int l,int r)
{
    if(R < l || L > r) return 1e9 + 10;
    if(L >= l and R <= r) return tree[at];
    int M = (L + R)/2;
    ll x = query_R(at * 2, L, M, l, r) ;
    ll y = query_R(at * 2 + 1, M + 1, R, l, r) ;
    return min(x, y);
}
void update(int at,int L,int R,int pos,ll val)
{
    if(pos > R || pos < L) return;
    if(L == pos and pos == R)
    {
        tree[at] = val + pos;
        bree[at] = val - pos;
        return;
    }
    int M = (L + R)/2;
    update(at * 2, L, M, pos, val);
    update(at * 2 + 1, M + 1, R,  pos, val);
    tree[at] = min(tree[at * 2], tree[at * 2 + 1]);
    bree[at] = min(bree[at * 2], bree[at * 2 + 1]);
}
int main()
{
    int N,Q; cin>> N >> Q;
    a.resize(N + 1);
    for(int i = 1;i <= N;i++) cin>> a[i];
    build_L(1, 1, N);
    build_R(1, 1, N);
    while(Q--)
    {
        int op; cin>> op;
        if(op == 2)
        {
            ll pos; cin>> pos;
            ll L = query_L(1, 1, N, 1, pos) + pos;
            ll R = query_R(1, 1, N, pos + 1, N) - pos;
            //cout<< L << ' ' << R << nl;
            cout<< min(L, R) << nl;
        }
        else if(op == 1){
            ll pos, val; cin>> pos >> val;
            update(1, 1, N, pos, val);
        }
    }
}
