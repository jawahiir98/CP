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
        int l,r; cin>> l >> r;
        if(2 * l > r) cout<< "YES" << nl;
        else cout<< "NO" << nl;
    }
}
