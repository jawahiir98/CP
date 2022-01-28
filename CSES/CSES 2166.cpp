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

vector <ll> a;
struct node {
	long long sum, pref;
	node(long long sum, long long pref) : sum(sum), pref(pref) {}
	node(long long x = 0) : sum(x), pref(max(0LL, x)) {}
	friend node operator+(const node& a, const node& b) {
		return {a.sum + b.sum, max(a.pref, a.sum + b.pref)};
	}
} tree[4 * E];
void build(int at,int L,int R)
{
    if(L == R){
        tree[at] = node(a[L]);
        return;
    }
    int M = (L + R)/2;
    build(at * 2, L, M);
    build(at * 2 + 1, M + 1, R);
    tree[at] = tree[at * 2] + tree[at * 2 + 1];
}
void update(int at,int L,int R,ll pos,ll val)
{
    if(pos > R || pos < L) return;
    if(L == R){
        tree[at] = node(val);
        return;
    }
    int M = (L + R)/2;
    update(at * 2, L, M, pos, val);
    update(at * 2 + 1, M + 1, R, pos, val);
    tree[at] = tree[at * 2] + tree[at * 2 + 1];
}
node query(int at,int L,int R,int l,int r)
{
    if(L > r || R < l) return 0LL;
    if(L >= l and R <= r) return tree[at];
    int M = (L + R)/2;
    node x = query(at * 2, L, M, l, r);
    node y = query(at * 2 + 1, M + 1, R, l , r);
    return  x + y;
}
int main()
{
    int N, Q; cin>> N >> Q;
    a.resize(N + 1);
    for(int i = 1;i <= N;i++) cin>> a[i];
    build(1, 1, N);
    while(Q--)
    {
        int op; cin>> op;
        if(op == 1){
            ll pos,val; cin>> pos >> val;
            update(1, 1, N, pos, val);
        }else{
            int l,r; cin>> l >> r;
            cout<< query(1, 1, N, l, r).pref << nl;
        }
    }
}
