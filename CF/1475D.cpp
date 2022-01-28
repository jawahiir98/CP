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
        ll N,M; cin>> N >> M;
        vector <ll> a(N),b(N);
        for(int i = 0;i < N;i++) cin>> a[i];
        for(int i = 0;i < N;i++) cin>> b[i];
        ll S = accumulate(a.begin(), a.end(), 0LL);
        if(S < M){
            cout<< -1 << nl;
            continue;
        }
        vector <int> least,great,taken;
        for(int i = 0;i < N;i++){
            if(b[i] == 1) least.pb(a[i]);
            else great.pb(a[i]);
        }
        sort(least.rbegin(), least.rend());
        sort(great.rbegin(), great.rend());
        S = 0;
        S = accumulate(great.begin(), great.end(), 0LL);
        int n1 = least.size();
        int n2 = great.size();
        int res = 1e9 + 10;
        int j = 0;
        for(int i = n2,j = 0;i >= 0;i--){
            while(S < M and j < n1){
                S += least[j];
                j++;
            }
            if(S >= M){
                res = min(res, 2 * i + j);
            }
            if(i > 0) S -= great[i - 1];
        }
        cout<< res << nl;
    }
}
