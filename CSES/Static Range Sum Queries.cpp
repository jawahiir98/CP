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
    int N,Q; cin>> N >> Q;
    vector <int> a(N);
    for(int i = 0;i < N;i++) cin>> a[i];
    vector <ll> range(N + 1, 0);
    for(int i = 0;i < N;i++) range[i + 1] = range[i] + a[i];
    while(Q--)
    {
        int a,b; cin>> a >> b;
        cout<< range[b] - range[a - 1] << nl;
    }
}
