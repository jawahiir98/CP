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

vector <int> a,tree(E * 4);
void build(int at,int L,int R)
{
    if(L == R) {tree[at] = a[L]; return; }
    int M = (L + R)/2;
    build(at * 2, L, M);
    build(at * 2 + 1, M + 1, R);
    tree[at] = min(tree[at * 2], tree[at * 2 + 1]);
}
int query(int at,int L,int R,int l,int r)
{
    if(L > r || R < l) return 1e9;
    if(L >= l && R <= r) return tree[at];
    int M = (L + R)/2;
    int x = query(at * 2, L, M, l, r);
    int y = query(at * 2 + 1, M + 1, R, l, r);
    return min(x, y);
}
int main()
{
    int N,Q; cin>> N >> Q;
    a.resize(N + 1);
    for(int i = 1;i <= N;i++) cin>> a[i];
    build(1, 1, N);
    while(Q--)
    {
        int a,b; cin>> a >> b;
        cout<< query(1, 1, N, a, b) << nl;
    }
}
