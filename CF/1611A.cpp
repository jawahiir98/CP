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
        int ev = -1,id = -1;
        for(int i = 0;i < s.size();i++){
            if((s[i] - '0') % 2 == 0){
                ev = 1,id = i;
                break;
            }
        }
        if(ev == -1) cout<< -1 << nl;
        else if(ev == 1 && (s[s.size() -1]-'0') % 2 == 0) cout<< 0 << nl;
        else if(ev == 1 && id == 0) cout<< 1 << nl;
        else cout<< 2 << nl;
    }
}
