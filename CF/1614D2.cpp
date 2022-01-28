/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 2e7 + 10;

bool vis[E];
int pr[E];
int main()
{
    int tot = 0;
    for(int i = 2;i <= E;i++){
        if(!vis[i]) pr[++tot] = i;
        for(int j = 1;j <= tot && i * pr[j] <= E;j++){
            vis[i *pr[j]] = 1;
            if(i == i/pr[j] * pr[j]) break;
        }
    }
    int N; scanf("%d", &N);
    vector <ll> cnt(E + 1, 0),dp(E + 1, 0);
    for(int i = 0;i < N;i++){
        int x; scanf("%d", &x);
        cnt[x] += 1;
    }
    for(int i = 1;i <= tot;i++){
        for(int j = E/pr[i];j >= 1;--j) cnt[j] += cnt[j * pr[i]];
    }
    dp[1] = cnt[1];
    ll ans = -1;
    for(int i = 1;i <= E;i++){
        for(int j = 1;i * pr[j] <= E;j++){
            int x = i * pr[j];
            dp[x] = max(dp[x], dp[i] + 1LL * (x - i) * cnt[x]);
        }
        ans = max(dp[i], ans);
    }
    cout<< ans << nl;
}
