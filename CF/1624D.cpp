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
        int N,K; cin>> N >> K;
        vector <int> a(26, 0);
        string s; cin>> s;
        for(int i = 0;i < N;i++) a[s[i] - 'a'] += 1;
        ll cnt = 0,rem = 0,ans = 0;
        for(int i = 0;i < 26;i++){
            rem += a[i] % 2;
            cnt += a[i] / 2;
        }
        ans = cnt / K;
        ans *= 2;
        cout<< ans + (rem + (2 * (cnt % K)) >= K ? 1 : 0) << nl;
    }
}
