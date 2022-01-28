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
        map <char, int> mp;
        for(int i = 0;i < N;i++) mp[s[i]] += 1;
        sort(s.begin(), s.end());
        cout<< s << nl;
    }
}
