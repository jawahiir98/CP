/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';

bool can(ll a,ll b,ll x)
{
    if(a == x || b == x) return true;
    if(a < b) swap(a, b);
    if(b > a - b) b = a - b;
    if(x > max(a, b) || a == 0 || b == 0) return false;
    ll cnt = (a - max(b, x))/(2 * b);
    cnt = max(1ll, cnt);
    return can(a - cnt * b, b, x);
}
int main()
{
    int T; cin>> T;
    while(T--)
    {
        ll a,b,x; cin>> a >> b >> x;
        if(can(a, b, x)) cout<< "YES" << nl;
        else cout<< "NO" << nl;
    }
}
