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
const int E = 2e6 + 10;

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
    vector <ll> F(E, 0),inv(E, 0);
    F[0] = inv[0] = 1;
    for(int i = 1;i < E;i++) F[i] = (F[i - 1] * i) % MOD,inv[i] = bigmod(F[i], MOD - 2);
    auto nCr = [&](ll n,ll r)
    {
        if(r > n || r < 0) return 0LL;
        return F[n] * inv[r] % MOD * inv[n - r] % MOD;
    };
    while(T--)
    {
        int N,M,K; cin>> N >> M >> K;
        vector <int> a(N);
        for(int i = 0;i < N;i++) cin>> a[i];
        sort(a.begin(), a.end());
        ll ans = 0;
        for(int i = 0;i < N - M + 1;i++){
            ll n = upper_bound(a.begin(), a.end(), a[i] + K) - a.begin();
            if(n - i >= M)ans += F[n - i - 1] * bigmod((F[n - i - M] * F[M - 1]) % MOD, MOD - 2);
            ans %= MOD;
        }
        cout<< ans << nl;
    }
}
