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
        ll a,b,c; cin>> a >> b >> c;
        if(a + b == 2 * c) cout<< 0 << nl;
        else if(a + b > c * 2){
            int x = (a + b - 2 * c + 1)/3;
            c += (a + b - 2 * c)/3;
            a -= x;
            cout<< abs(a + b - 2*c) << nl;
        }
        else{
            int x = (2 * c - (a + b) + 1)/3;
            c -= x;
            a += x;
            cout<< abs(a + b - 2*c) << nl;
        }
    }
}
