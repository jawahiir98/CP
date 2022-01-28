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
        ll K,x; cin>> K >> x;
        auto get = [&](ll n)
        {
           return 1ll * n * (n + 1)/2;
        };
        ll l = 1,r = 2 * K - 1,mid;
        ll res = 2 * K - 1;
        while(l <= r){
            mid = (l + r)/2;
            bool can = false;
            if(mid >= K){
                can = (get(K) + get(K - 1) - get(2 * K - 1 - mid) >= x);
            }
            else{
                can = (get(mid) >= x);
            }
            if(can){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout<< res << nl;
    }
}
