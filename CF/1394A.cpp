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
        int N,D,M; cin>> N >> D >> M;
        vector <int> a(N);
        for(int i = 0;i < N;i++){
            cin>> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        for(int x : a) if(x > M) ans += x;
        cout<< ans << nl;
    }
}
