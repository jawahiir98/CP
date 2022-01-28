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
        ll K,N; cin>> N >> K;
        vector <int> a(N);
        for(int i = 0;i < N;i++) cin>> a[i];
        sort(a.begin(),a.end());
        ll S = accumulate(a.begin(), a.end(), 0LL);
        if(S <= K){
            cout<< 0 << nl;
            continue;
        }
        vector <ll> cum(N + 1, 0);
        for(int i = 0;i < N;i++) cum[i + 1] = cum[i] + a[i];
        ll res = 1e18 + 10;
        for(int i = 0;i < N;i++){
            ll sum = K - cum[N - i] + a[0];
            ll lagbe = (sum / (i + 1));
            if(lagbe * (i + 1) > sum) lagbe--;
            lagbe = a[0] - lagbe;
            res = min(res, i + max(0LL, lagbe));
        }
        cout<< res << nl;
    }
}
