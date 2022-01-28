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
    int N; cin>> N;
    int M = N;
    vector <int> a;
    while(N){
        a.pb(N % 10);
        N /= 10;
    }
    reverse(a.begin(), a.end());
    cout<<  M + (a[1] * 100 + a[2] * 10 + a[0]) + (a[2] * 100 + a[0] * 10 + a[1]) << nl;
}
