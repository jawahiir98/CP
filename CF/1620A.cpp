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
        bool ok = true;
        if(N == 2){
            if(s == "EN" || s == "NE") ok = false;
        }
        else if(s[0] == 'E' && s[1] == 'E' && s[N - 1] == 'N') ok = false;
        else if(s[0] == 'E' && s[1] == 'E' && s[N - 1] == 'N') ok = false;
        else if(s[0] == 'N' && s[1] == 'E' && s[N - 1] == 'E') ok = false;
        cout<< (ok ? "YES" : "NO") << nl;
    }
}
