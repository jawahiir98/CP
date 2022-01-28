/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 1e5 + 10;
const int MOD = 1e9 + 7;

int N;
ll tree[4 * E];
vector <pair<int, int>> A;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first) return a.second > b.second;
    else return a.first < b.first;
}
void update(int at,int L, int R,int pos, int val)
{
    if(L > pos || R < pos) return;
    if(L == R && L == pos){
        tree[at] = val;
        return;
    }
    int M = (L + R)/2;
    update(2 * at, L, M, pos, val);
    update(2 * at + 1, M + 1, R, pos, val);
    tree[at] = tree[at * 2] + tree[at * 2 + 1];
    tree[at] %= MOD;
}
ll query(int at,int L, int R, int l, int r)
{
    if(R < l || L > r) return 0;
    if(l <= L && R <= r) return tree[at];
    int M = (L + R)/2;
    return (query(2 * at, L, M, l, r) + query(2 * at + 1, M + 1, R, l, r)) % MOD;
}
int main()
{
    int T,cs = 0; scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        for(int i = 0;i < N;i++){
            int x; cin>> x;
            A.pb({x, i + 1});
        }
        sort(A.begin(), A.end(), cmp);
        ll res = 0;
        for(int i = 0;i < N;i++){
            int id = A[i].S;
            res = query(1, 0, N, 0, id - 1);
            update(1, 0, N, id, res + 1);
        }
        res = query(1, 0, N, 0, N) % MOD;
        printf("Case %d: %lld\n",++cs, res);
        A.clear();
        memset(tree, 0, sizeof(tree));
    }
}
