/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 3e4 + 10;

vector <int> a;
vector <pair<int, int>> sm;
int N;
void build(int at,int l,int r)
{
    if(l == r)
    {
        sm[at] = {a[l], l};
        return;
    }
    int M = (l + r)/2;
    build(at * 2, l, M);
    build(at * 2 + 1, M + 1, r);
    sm[at] = min(sm[at * 2], sm[at * 2 + 1]);
}
pair<int, int> query(int at,int L,int R,int l,int r)
{
    if(r < L || l > R) return {1e9, 1e9};
    if(l <= L && r >= R) return sm[at];
    int M = (L + R)/2;
    pair<int, int> x = query(at * 2, L, M,l, r);
    pair<int, int> y = query(at * 2 + 1, M + 1, R, l, r);
    return min(x, y);
}
ll area(int x,int y)
{
    if(x > y) return 0;
    pair <int, int> p = query(1, 1, N, x, y);
    ll a = (y - x + 1) * p.first;
    ll b = max(area(x, p.second - 1), area(p.second + 1, y));
    return max(a, b);
}
int main()
{
    int T,cs = 0; scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        a.resize(N + 1);
        sm.resize(N * 4 + 5);
        for(int i = 1;i <= N;i++) scanf("%d", &a[i]);
        build(1, 1, N);
        printf("Case %d: %lld\n", ++cs, area(1, N));
    }
}
