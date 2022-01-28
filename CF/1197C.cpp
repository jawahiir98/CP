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
    int N,K; cin>> N >> K;
    vector <int> a(N),dif;
    for(int i = 0;i < N;i++){
        cin>> a[i];
        if(i) dif.pb(a[i] - a[i - 1]);
    }
    sort(dif.begin(), dif.end());
    ll res = 0;
    for(int i = 0;i < N - K;i++){
        res += dif[i];
    }
    cout<< res << nl;
}
