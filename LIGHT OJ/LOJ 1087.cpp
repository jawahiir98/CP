/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 2e5 + 1e3;

int a[E * 2],tree[E * 4],mark[E * 2];
void build(int at,int L,int R)
{
    if(L == R){tree[at] = mark[L]; return;}
    int M = (L + R)/2;
    build(at * 2, L, M);
    build(at * 2 + 1, M + 1, R);
    tree[at] = tree[at * 2] + tree[at * 2 + 1];
}
int query(int at,int L,int R,int l,int r)
{
    if(L > r || R < l) return 0;
    if(L >= l && R <= r) return tree[at];
    int M = (L + R)/2;
    ll left = query(2 * at, L, M, l, r);
    ll right = query(2 * at + 1, M + 1, R, l, r);
    return left + right;
}
void update(int at,int L,int R,int val,int pos)
{
    if(pos < L || pos > R) return;
    if(pos <= L && pos >= R){ tree[at] = val; return;}
    int M = (L + R)/2;
    update(at * 2, L , M, val, pos);
    update(at * 2 + 1, M + 1, R, val, pos);
    tree[at] = tree[at * 2] + tree[at * 2 + 1];
}
int N,Q;
int main()
{
    int T,cs = 0; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &N, &Q);
        for(int i = 1;i <= N;i++) scanf("%d", &a[i]),mark[i] = 1;
        build(1, 1, N * 2);
        int NN = N * 2;
        printf("Case %d:\n",++cs);
        while(Q--)
        {
            char c; int x; cin>> c >> x;
            if(c == 'c'){
                int l = 1,r = N,M,res = -1;
                while(l <= r)
                {
                    M = (l + r)/2;
                    if(query(1, 1, NN, 1, M) >= x){
                        r = M - 1;
                        res = M;
                    }else{
                        l = M + 1;
                    }
                }
                if(res == -1) puts("none");
                else{
                    printf("%d\n", a[res]);
                    update(1, 1, NN, 0, res);
                }
            }
            else{
                N++;
                a[N] = x;
                update(1, 1, NN, 1, N);
            }
        }
        memset(mark, 0, sizeof(mark));
        memset(tree, 0, sizeof(tree));
    }
}
