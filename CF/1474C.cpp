/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';

void solve()
{
    int N; cin>> N;
    vector <int> a(2 * N);
    map <int, int> mp;
    for(int i = 0;i < N * 2;i++){
        cin>> a[i];
        mp[a[i]] += 1;
    }
    sort(a.rbegin(),a.rend());
    auto can = [&](int x)
    {
        //cout<< x << ": " << nl;
        multiset <int> s;
        for(int i = 1;i < 2 * N;i++)  s.insert(a[i]);
        s.erase(s.find(x));
        int cur =  a[0];
        while(!s.empty())
        {
            int u = *prev(s.end());
            s.erase(s.find(u));
            int v = cur - u;
            if(s.find(v) == s.end()) return false;
            s.erase(s.find(v));
            //cout<< u << ' ' << v << nl;
            cur = max(u , v);
        }
        return true;
    };
    int bad = -1;
    for(int i = 1;i < 2 * N;i++){
        if(can(a[i])){
            bad = i;
            break;
        }
    }
    if(bad == -1) puts("NO");
    else{
        cout<< "YES" << nl;
        cout<< a[bad] + a[0] << nl;
        cout<< a[bad] << ' ' << a[0] << nl;
        multiset <int> s;
        mp[a[bad]]--;
        for(int i = 1;i < 2 * N;i++) s.insert(a[i]);
        s.erase(s.find(a[bad]));
        int cur =  a[0];
        while(!s.empty())
        {
            int u = *prev(s.end());
            s.erase(s.find(u));
            int v = cur - u;
            s.erase(s.find(v));
            cur = max(u, v);
            cout<< u << ' ' << v << nl;
        }
    }
}
int main()
{
    int T; cin>> T;
    while(T--)
    {
        solve();
    }
}
