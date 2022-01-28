/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 3e5 + 10;
const int M = 1e6 + 10;
inline int nextint(){ int x; scanf("%d",&x); return x; }

vector <ll> a,tree(4 * E),cnt(E);
void build(int at,int L,int R)
{
    if(L == R){tree[at] = a[L]; return; }
    int M = (L + R)/2;
    build(at * 2, L, M);
    build(at * 2 + 1, M + 1, R);
    tree[at] = tree[at * 2] + tree[at * 2 + 1];
}
void update(int at,int L,int R,int pos,ll val)
{
    if(pos > R || pos < L) return;
    if(L == R){
        tree[at] = val;
        return;
    }
    int M = (L + R)/2;
    update(at * 2, L, M, pos, val);
    update(at * 2 + 1, M + 1, R, pos, val);
    tree[at] = tree[at * 2] + tree[at * 2 + 1];
}
ll query(int at,int L,int R,int l,int r)
{
    if(L > r || R < l) return 0;
    if(L >= l and R <= r) return tree[at];
    int M = (L + R)/2;
    ll x = query(at * 2, L, M, l, r);
    ll y = query(at * 2 + 1, M + 1, R, l, r);
    return x + y;
}
int main()
{
    for(int i = 1;i + i <= M;i++){
        for(int j = i;j < M;j += i) cnt[j] += cnt[i];
    }
    int N = nextint(), M = nextint();
    a.resize(N + 1);
    for(int i = 1;i <= N;i++) a[i] = nextint();
    build(1, 1, N);
    while(M--)
    {
        int t = nextint();
        if(t == 1)
        {
            int pos = nextint(), val = nextint();
            update(1, 1, N, pos, (ll)val);
        }
        else{
            int l = nextint(), r = nextint();
            printf("%lld\n", query(1, 1, N, l, r));
        }
    }
}
