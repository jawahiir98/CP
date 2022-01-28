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
        ll A,S; cin>> A >> S;
        vector <int> rs,a,s,b;
        while(A){
            a.pb(A % 10);
            A /= 10;
        }
        while(S){
            s.pb(S % 10);
            S /= 10;
        }
        //while(a.size() < s.size()) a.pb(0);
        bool ok = true;
        for(int i = 0,j = 0;j < s.size();i++,j++){
            if(i >= a.size()){
                b.pb(s[j]);
                continue;
            }
            if(a[i] > s[j]){
                b.pb(s[j] - a[i] + 10);
                j++;
            }
            else{
                b.pb(s[j] - a[i]);
                //cout<< s[j] - a[i] << ' ';
            }
            if(j == s.size()- 1&& i != a.size() - 1) ok = false;
        }
        if(!ok){
            cout<< -1 << nl;
            continue;
        }
        for(int i = 0;i < b.size();i++){
            if(i >= a.size()) a.pb(0);
            int x = b[i] + a[i];
            if(x >= 10) rs.pb(x - 10),rs.pb(1);
            else rs.pb(x);
        }
        if(rs != s) cout<< -1 <<nl;
        else{
            reverse(b.begin(), b.end());
            int id = 0;
            while(b[id] == 0) id++;
            for(int i = id;i < b.size();i++) cout<< b[i];
            cout<< nl;
        }
    }
}
