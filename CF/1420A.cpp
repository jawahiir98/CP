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
        vector <int> a(N),b;
        for(int i = 0;i < N;i++) cin>> a[i];
        b = a;
        sort(b.rbegin(), b.rend());
        if(a == b && !is_sorted(a.begin(), a.end())){
            cout<< "NO" << nl;
        }
        else cout<< "YES" << nl;
    }
}
