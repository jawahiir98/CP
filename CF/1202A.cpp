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
        string s,p; cin>> s >> p;
        reverse(p.begin(), p.end());
        reverse(s.begin(), s.end());
        int pos1 = 0,pos2 = 0;
        int N = s.size();
        for(int i = 0;i < p.size() and p[i] == '0';i++) pos1++,pos2++;
        for(int i = pos1;i < s.size() and s[i] == '0';i++) pos2++;
        cout<< pos2 - pos1 << nl;
     }
}
