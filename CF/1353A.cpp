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
    int N,M,D; cin>> N >> D >> M;
    vector <int> a(N);
    for(int i = 0;i < N;i++){
        cin>> a[i];
    }
    sort(a.rbegin(),a.rend());
    int ans = 0;
    for(auto x : a) cout<< x << ' '; cout<< nl;
    for(int i =0;i < N;i++){
        ans += a[i];
        cout<< ans << ' ' << a[i] << nl;
    }
}
