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

vector <ll> a,tree(4 * E);
void build(int at,int L,int R)
{
    if(L == R){tree[at] = a[L]; return; }
    int M = (L + R)/2;
    build(at * 2, L, M);
    build(at * 2 + 1, M + 1, R);
    tree[at] = max(tree[at * 2], tree[at * 2 + 1]);
}
int query(int at,int L,int R,int val)
{
    if(tree[at] < val) return 0;
    if(L == R) return L;
    int M = (L + R)/2;
    if(tree[at * 2] >= val) return query(at * 2, L, M, val);
    else return query(at * 2 + 1, M + 1, R, val);
}
void update(int at,int L,int R,int pos, int val)
{
    if(pos < L || pos > R) return;
    if(L == R){tree[at] -= val; return; }
    int M = (L + R)/2;
    update(at * 2, L, M, pos, val);
    update(at * 2 + 1, M + 1, R, pos, val);
    tree[at] = max(tree[at * 2], tree[at * 2 + 1]);
}
int main()
{
    int N, Q; cin>> N >> Q;
    a.resize(N + 1);
    for(int i = 1;i <= N;i++) cin>> a[i];
    build(1, 1, N);
    while(Q--)
    {
        int x; cin>> x;
        int id = query(1, 1, N, x);
        cout<< id << ' ';
        if(id) update(1, 1, N, id, x);
    }
}
