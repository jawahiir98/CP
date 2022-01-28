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
        int N,M; cin>> N >> M;
        if(N == 1 && M == 1) cout<< 0 << nl;
        else if(N == 1 || M == 1) cout<< 1 << nl;
        else cout<< 2 << nl;
    }
}
