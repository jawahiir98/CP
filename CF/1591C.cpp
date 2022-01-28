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
        vector <int> left,right;
        for(int i = 0;i < N;i++){
            int x; cin>> x;
            if(x < 0) left.pb(x);
            else right.pb(x);
        }
        ll ans = 0;
        int n = right.size();
        sort(right.rbegin(), right.rend());
        for(int i = 0;i < n;i += K){
            if(i == 0) ans += right[i];
            else ans += 2 * right[i];
        }
        int m = left.size();
        sort(left.begin(), left.end());
        for(int i = 0;i < m;i += K){
            if(i == 0) ans -= left[i];
            else ans -= 2 * left[i];
        }
        if(n > 0 && m > 0) ans += min(-left[0], right[0]);
        cout<< ans << nl;
    }
}
