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
    int Test; cin>> Test;
    while(Test--)
    {
        string s,t,p; cin>> s >> t >> p;
        bool ok = true;
        vector <int> S(26, 0),T(26, 0),P(26, 0);
        for(char c : s) S[c - 'a']++;
        for(char c : t) T[c - 'a']++;
        for(char c : p) P[c - 'a']++;
        for(int i = 0;i < 26;i++){
            if(S[i] + P[i] < T[i]) ok = false;
        }
        string res = "";
        for(int i = 0,j = 0;i < t.size();i++){
            if(t[i] == s[j]){
                res += s[j];
                if(S[s[j] - 'a']) S[s[j] - 'a']--;
                else P[t[i] - 'a']--;
                j++;
            }else{
                if(P[t[i] - 'a']){
                    res += t[i];
                    P[t[i] - 'a']--;
                }
                else ok = false;
            }
            if(i == t.size() - 1 && j != s.size())  ok = false;
        }
        if(!ok){
            cout<< "NO" << nl;
            continue;
        }
        cout<< (res == t ? "YES" : "NO") << nl;
    }
}
