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
        int N; cin>> N;

        auto query = [&](int l, int r)
        {
            cout<< "? " << l << ' ' << r << endl;
            ll a; cin>> a;
            return a;
        };
        ll tota = query(1, N);
        ll l = 1,r = N,Mid;
        while(l < r)
        {
            Mid = (l + r - 1)/2;
            if(query(1, Mid) == tota) r = Mid;
            else l = Mid + 1;
        }
        ll i,j,k;
        j = r - query(1, r) + query(1, r - 1);
        i = j + query(1, j - 2) - query(1, j - 1) - 1;
        k = r;
        cout<< "! " << i << ' ' << j << ' ' << k << nl;
    }
}
