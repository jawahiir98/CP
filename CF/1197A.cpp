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
        vector <int> a(N + 1);
        for(int i = 1;i <= N;i++) cin>> a[i];
        sort(a.begin(), a.end());
        int ans = min(N - 2, a[N - 1] - 1);
        cout<< ans << nl;
    }
}

