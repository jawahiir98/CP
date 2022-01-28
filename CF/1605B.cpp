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
        int N ; cin>> N;
        string s; cin>> s;
        if(is_sorted(s.begin(), s.end())){
            cout<< 0 << nl;
            continue;
        }
        string p = s;
        sort(p.begin(), p.end());
        cout<< 1 << nl;
        vector <int> ind;
        for(int i = 0;i < N;i++){
            if(p[i] != s[i]) ind.pb(i);
        }
        cout<< (int)ind.size() << ' ';
        for(int x : ind) cout<< x + 1 << ' ';
        cout<< nl;
     }
}
