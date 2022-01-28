/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 1e5 + 1;
const int LIM = 1429433;

vector <int> a(E),tree(4 * LIM);
void build(int at,int L,int R)
{
    if(L == R){
        tree[at] = L % 2;
        return;
    }
    int M = (L + R)/2;
    build(at * 2, L, M);
    build(at * 2 + 1, M + 1, R);
    tree[at] = tree[at * 2] + tree[at * 2 + 1];
}
int query(int at,int L,int R,int pos)
{
    if(L == R) return L;
    int M = (L + R)/2;
    if(tree[at * 2] >= pos) return query(at * 2, L, M, pos);
    else return query(at * 2 + 1, M + 1, R, pos - tree[at * 2]);
}
void update(int at,int L,int R,int pos)
{
    if(L == R){
        tree[at] = 0;
        return;
    }
    int M = (L + R)/2;
    if(tree[at * 2] >= pos) update(at * 2, L, M, pos);
    else update(at * 2 + 1, M + 1, R, pos - tree[at * 2]);
    tree[at] = tree[at * 2] + tree[at * 2 + 1];
}
int main()
{
    build(1, 1, LIM);
    a[1] = 1;
    for(int i = 2;i < E;i++){
        a[i] = query(1, 1, LIM, i);
        for(int j = (LIM / a[i]) * a[i];j >= a[i];j -= a[i]){
            update(1, 1, LIM, j);
        }
    }
    int T,cs = 0; scanf("%d", &T);
    while(T--)
    {
        int N; scanf("%d", &N);
        printf("Case %d: %d\n", ++cs, a[N]);
    }
}
