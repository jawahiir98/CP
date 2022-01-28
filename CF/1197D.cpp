/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';

int main()
{
    int N,M,K; cin>> N >> M >> K;
    vector <ll> a(N);
    for(int i = 0;i < N;i++) cin>> a[i];
    vector <ll> dp(N + 1, 0);
    dp[0] = a[0];
    ll cur = a[0];
    for(int i = 1;i < N;i++){
        cur = max(a[i], cur + a[i]);
        dp[i] = max(dp[i - 1], cur);
    }
    cout<< dp[N - 1] << nl;
}
