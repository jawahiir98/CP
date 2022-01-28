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
        int tw = (int)sqrt(N);
        int tr = (int)cbrt(N);
        int tot = tw + tr - (int)sqrt(tr);
        cout<< tot << nl;
    }
}
