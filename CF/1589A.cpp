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
        ll u,v; cin>> u >> v;
        ll x = -u * u,y = v * v;
        cout<< x << ' ' << y << nl;
    }
}
