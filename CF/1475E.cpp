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
    vector <ll> fac(1e3 + 10, 0);
    fac[0] = 1;
    for(int i = 1;i < 1e3 + 5;i++) fac[i] = (fac[i - 1] * i) % MOD;
    while(T--)
    {
        int N,K; cin>> N >> K;
        vector <int> a(N),pos(N + 1, 0),cnt(N + 1, 0);
        for(int i = 0;i < N;i++){
            cin>> a[i];
            cnt[a[i]] += 1;
        }
        ll sum = 0;
        sort(a.rbegin(), a.rend());
        for(int i = 0;i < min(N, K);i++){
            sum += a[i];
            pos[a[i]] += 1;
        }
        ll res = 1;
        for(int i = 0;i < N;i++){
            if(pos[a[i]]){
                ll tmp = fac[pos[a[i]]] * (fac[cnt[a[i]] - pos[a[i]]]);
                tmp %= MOD;
                if(tmp == 0) tmp = 1;
                res *= (fac[cnt[a[i]]] * bigmod(tmp, MOD - 2)) % MOD;
                pos[a[i]] = 0;
            }
        }
        cout<< res << nl;
    }
}
