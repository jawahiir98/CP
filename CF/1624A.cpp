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
        vector <int> a(N);
        for(int i = 0;i < N;i++) cin>> a[i];
        sort(a.rbegin(), a.rend());
        ll ans = 0,tar = a[0],cur = 0;
        for(int i = 0;i < N;i++){
            ans += (tar - a[i] - cur);
            cur = ans;
        }
        cout<< ans << nl;
    }
}
