/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 2e5 + 10;

vector <ll> a,xsum;
int main()
{
    int N,q; cin>> N >> q;
    a.resize(N + 1, 0);
    xsum.resize(N + 2, 0);
    for(int i = 1;i <= N;i++) cin>> a[i];
    for(int i = 1;i <= N;i++) xsum[i + 1] = xsum[i] ^ a[i];
    while(q--)
    {
        int a,b; cin>> a >> b;
        cout<< (xsum[b + 1]^xsum[a]) << nl;
    }
}
