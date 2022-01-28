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
        vector <int> a(N);
        for(int i = 0;i < N;i++) cin>> a[i];
        ll S = accumulate(a.begin(), a.end(), 0LL),tmp;
        tmp = S;
        ll cnt =  (S + N - 2)/(N - 1);
        sort(a.begin(), a.end());
        S = cnt * (N - 1);
        if(S < (ll)a[N - 1] * (N - 1)) S = (ll)a[N - 1] * (N - 1);
        cout<< S - tmp << nl;
    }
}
