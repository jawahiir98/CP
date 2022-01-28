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
        string s,t; cin>> s >> t;
        sort(s.begin(),s.end());
        int a = 0,b = 0,c = 0;
        if(t == "abc"){
            for(int i = 0;i < s.size();i++){
                a += s[i] == 'a';
                b += s[i] == 'b';
                c += s[i] == 'c';
            }
            if(a){
                while(a--) cout<< 'a';
                while(c--) cout<< 'c';
                while(b--) cout<< 'b';
            }
            else{
                cout<< s << nl;
                continue;
            }
            for(int i = 0;i < s.size();i++){
                if(s[i] == 'a' || s[i] == 'b' || s[i] == 'c') continue;
                cout<< s[i];
            }
            cout<< nl;
            continue;
        }
        else cout<< s << nl;
    }
}
