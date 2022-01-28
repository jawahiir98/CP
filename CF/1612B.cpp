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
        int N,a,b; cin>> N >> a >> b;
        vector <int> pos(N + 1, 0);
        pos[a] = 1,pos[b] = 1;
        vector <int> rs;
        rs.pb(a);
        for(int i = N;i >= 1;i--){
            if(pos[i]) continue;
            pos[i] = 1;
            rs.pb(i);
        }
        rs.pb(b);
        int mn_half = 1e9,mx_half = -1;
        for(int i = 0;i < N/2;i++) mn_half = min(mn_half, rs[i]);
        for(int i = 0;i < N/2;i++) mx_half = max(mx_half, rs[i + N/2]);
        if(mn_half != a || mx_half != b) cout<< -1 << nl;
        else{
            for(auto i : rs) cout<< i << ' ';
            cout<< nl;
        }
    }
}
