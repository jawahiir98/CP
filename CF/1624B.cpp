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
        int a,b,c; cin>> a >> b >> c;
        if(b - a == c - b){
            cout<< "YES" << nl;
            continue;
        }
        int d = b - a;
        if(d + b > c && (d + b) % c == 0){
            //cout<< d + b << " c ";
            cout<< "YES" << nl;
            continue;
        }
        d = c - b;
        if(b - d > a and (b - d) % a == 0){
            //cout<< (b - d) << " a ";
            cout<< "YES" << nl;
            continue;
        }
        d = c - a;
        if(d % 2 == 0 and a + d/2 > b and (a + d/2) % b == 0){
            //cout<< (a + d/2) << " b ";
            cout<< "YES" << nl;
            continue;
        }
        cout<< "NO" << nl;
    }
}
