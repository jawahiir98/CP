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
        vector <int> x(N),y(N);
        for(int i = 0;i < N;i++) cin>> x[i];
        for(int i = 0;i < N;i++) cin>> y[i];
        sort(x.begin(), x.end());
        vector <int> sz(N);
        for(int i = 0,j = 0;i < N;i++){
            while(j < N and x[i] + K >= x[j]) j++;
            sz[i] = j;
        }
        vector <int> mx(N + 1, 0);
        for(int i = N - 1;i >= 0;i--) mx[i] = max(mx[i + 1], sz[i] - i);
        int ans = 0;
        for(int i = 0;i < N;i++){
            ans = max(ans, mx[sz[i]] + sz[i] - i);
        }
        cout<< ans << nl;
    }
}
