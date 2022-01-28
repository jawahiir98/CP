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

vector <ll> lazy(E * 4),tree(E * 4);
void propagate(int at,int L,int R)
{
    if(L != R){
        lazy[at * 2] = lazy[at];
        lazy[at * 2 + 1] = lazy[at];
    }
    tree[at] = (R - L + 1) * lazy[at];
    lazy[at] = -1;
}
void update(int at,int L,int R,int l,int r,ll val)
{
    if(lazy[at] != -1) propagate(at, L, R);
    if(L > r || R < l) return;
    if(L >= l and R <= r){
        if(L != R){
            lazy[at * 2] = val;
            lazy[at * 2 + 1] = val;
        }
        tree[at] = (R - L + 1) * val;
        return;
    }
    int M = (L + R)/2;
    update(at * 2, L, M, l, r, val);
    update(at * 2 + 1, M + 1, R, l, r, val);
    tree[at] = tree[at * 2] + tree[at * 2 + 1];
}
ll query(int at,int L,int R,int l,int r)
{
    if(lazy[at] != -1) propagate(at, L, R);
    if(L > r || R < l) return 0;
    if(L >= l and R <= r) return tree[at];
    int M = (L + R)/2;
    ll x = query(at * 2, L, M, l, r);
    ll y = query(at * 2 + 1, M + 1, R, l, r);
    return x + y;
}
void build(int at,int L,int R)
{
    lazy[at] = -1,tree[at] = 0;
    if(L == R) return;
    int M = (L + R)/2;
    build(at * 2, L, M);
    build(at * 2 + 1, M + 1, R);
}
int main()
{
    int T = nextint(),cs = 0;
    while(T--)
    {
        int N = nextint(),q = nextint();
        printf("Case %d:\n", ++cs);
        build(1, 0, N - 1);
        while(q--)
        {
            int op,l,r; scanf("%d%d%d", &op, &l, &r);
            if(op == 1){
                ll val = nextint();
                update(1, 0, N - 1, l, r, val);
            }else{
                ll up = query(1, 0, N - 1, l, r);
                ll down = (r - l + 1);
                ll g = __gcd(down, up);
                if(up % down == 0) printf("%lld\n", up/down);
                else printf("%lld/%lld\n", up/g, down/g);
            }
        }
    }
}
