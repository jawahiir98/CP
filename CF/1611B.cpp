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
        int a,b; cin>> a >> b;
        if(a > b) swap(a, b);
        cout<< min(min(a, b), (a + b)/4) << nl;
    }
}
