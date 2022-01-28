/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int MOD = 1e9 + 7;

ll bigmod(ll x,ll y)
{
    if(y == 0) return 1;
    ll ret = bigmod(x, y/2);
    ret = (ret * ret) % MOD;
    if(y & 1) ret = (ret * x) % MOD;
    return ret;
}
int main()
{
    int T; cin>> T;
    while(T--)
    {
        int N,M; cin>> N >> M;
        int bit = 0;
        for(int i = 0;i < M;i++){
            int l,r,val; cin>> l >> r >> val;
            bit |= val;
        }
        bit %= MOD;
        cout<< (bigmod(2, N - 1) * bit * 1LL) % MOD << nl;
    }
}
