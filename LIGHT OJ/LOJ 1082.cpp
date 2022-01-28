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

vector <int> a,tree(E * 4);
void build(int at,int L,int R)
{
    if(L == R){tree[at] = a[L]; return;}
    int M = (L + R)/2;
    build(at * 2,L, M);
    build(at * 2 + 1,M + 1, R);
    tree[at] = min(tree[at * 2], tree[at * 2 + 1]);
}
int query(int at,int L,int R,int l,int r)
{
    if(L > r || R < l) return 1e9;
    if(L >= l && R <= r) return tree[at];
    int M = (L + R)/2;
    int x = query(at * 2, L, M, l, r);
    int y = query(at * 2 + 1,M + 1, R, l, r);
    return min(x, y);
}
int main()
{
    int cs = 0,T = nextint();
    while(T--)
    {
        int N = nextint(),Q = nextint();
        a.resize(N + 1);
        for(int i = 1;i <= N;i++) a[i] = nextint();
        build(1, 1, N);
        printf("Case %d:\n", ++cs);
        while(Q--)
        {
            int l = nextint(),r = nextint();
            printf("%d\n", query(1, 1, N, l, r));
        }
    }
}
