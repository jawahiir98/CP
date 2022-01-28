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
        map <int, int> mp;
        for(int i = 0;i < N;i++){
            cin>> a[i];
        }
        sort(a.begin(), a.end());
        bool ok = true;
        for(auto x: a){
            while(x){
                if(x <= N and mp[x] == 0){mp[x] =1; break; }
                x /= 2;
            }

        }
        for(int i = 1;i <= N;i++){
            ok &= mp[i];
        }
        cout<<(ok ? "YES" : "NO") << nl;
    }
}
