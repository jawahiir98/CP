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
    int T; cin>> T;
    while(T--)
    {
        int N; cin>> N;
        vector <ll> a(N),b(N),c(N),dp(N + 1);
        for(int i = 0;i < N;i++) cin>> c[i];
        for(int i = 0;i < N;i++) cin>> a[i];
        for(int i = 0;i < N;i++) cin>> b[i];
        dp[0] = -1;
        ll res = 0,cur_mx = 0;
        for(int i = 1;i < N;i++){
            if(a[i] == b[i]){
                cur_mx = c[i] + 1;
            }else{
                cur_mx = max(c[i] + abs(a[i] - b[i]) + 1, cur_mx + c[i] - abs(a[i] - b[i]) + 1);
            }
            res = max(res, cur_mx);
        }
        cout<< res << nl;
    }
}
