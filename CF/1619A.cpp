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
        string s; cin>> s;
        int N = s.size();
        if(N & 1){
            cout<< "NO" << nl;
        }
        else{
            bool ok = true;
            for(int i = 0;i < N/2;i++){
                ok &= (s[i] == s[i + N/2]);
            }
            cout<<(ok ? "YES" : "NO") << nl;
        }
    }
}
