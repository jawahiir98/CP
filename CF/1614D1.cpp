/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 5e6 + 100;

int main()
{
    int N; cin>> N;
    vector <ll> a(N),dp(E + 1, 0),cnt(E + 1, 0);
    for(int i = 0;i < N;i++) cin>> a[i],cnt[a[i]] += 1;
    for(int i = 1;i <= E;i++){
        for(int j = i + i;j <= E;j += i) cnt[i] += cnt[j];
    }
    dp[1] = cnt[1];
    ll res = -1;
    for(int i = 1;i < E + 1;i++){
        for(int j = i + i;j <= E;j += i){
            dp[j] = max(dp[j], dp[i] + (ll)(j - i) * cnt[j]);
        }
        res = max(res,  dp[i]);
    }
    cout<< res << nl;
}
