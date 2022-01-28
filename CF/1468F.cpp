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
        vector <pair<int, int>> ang;
        for(int i = 0;i < N;i++){
            int a,b,c,d; cin>> a >> b >> c >> d;
            int x = c - a,y = d - b,g = __gcd(abs(x), abs(y));
            x /= g,y /= g;
            ang.pb({x, y});
        }
        map <pair<int, int>, int> mp;
        for(pair<int, int> p : ang) mp[p] += 1;
        ll res = 0;
        for(int i = 0;i < N;i++){
            if(mp[ang[i]] == 0) continue;
            auto [x, y] = ang[i];
            ll g1 = mp[{x, y}];
            ll g2 = mp[{-x, -y}];
            res += g1 * g2;
            mp[{x, y}] = 0,mp[{-x, -y}] = 0;
        }
        cout<< res << nl;
    }
}
