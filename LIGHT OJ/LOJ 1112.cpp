/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 1e5 + 100;
inline int nextint(){ int x; scanf("%d",&x); return x; }

vector <ll> a,tree(E * 4);
void build(int at,int L,int R)
{
    if(L == R){tree[at] = a[L]; return; }
    int M = (L + R)/2;
    build(at * 2, L, M);
    build(at * 2 + 1, M + 1, R);
    tree[at] = (tree[at * 2] + tree[at * 2 + 1]);
}
void update(int at,int L,int R,int pos,int val)
{
    if(pos < L || pos > R) return;
    if(L == R){
        if(val == 0) tree[at] = val;
        else tree[at] += val;
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
    ll y = query(at * 2 + 1,M + 1, R, l, r);
    return x + y;
}
int main()
{
    int T = nextint(),cs = 0;
    while(T--)
    {
        int N,q; cin>> N >> q;
        a.resize(N + 1);
        for(int i = 1;i <= N;i++) a[i] = nextint();
        build(1,1, N);
        printf("Case %d:\n", ++cs);
        while(q--)
        {
            int op = nextint();
            if(op == 1){
                int pos = nextint(),val = 0;
                ++pos;
                printf("%lld\n", query(1, 1, N, pos, pos));
                update(1, 1, N, pos, val);
            }
            else if(op == 2){
                int pos = nextint(),val = nextint();
                pos++;
                update(1, 1, N, pos, val);
            }else{
                int l = nextint(),r = nextint();
                ++r, ++l;
                printf("%lld\n", query(1, 1, N, l, r));
            }
        }
    }
}
