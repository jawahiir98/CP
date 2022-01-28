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
    int T = 1;
    while(T--)
    {
        int N; cin>> N;
        vector <int> a(N);
        int I;
        for(int i = 0;i < N;i++){
            cin>> a[i];
            if(a[i] == N) I = i;
        }
        bool ok = true;
        for(int i = I - 1;i >= 0;i--) if(a[i] > a[i + 1]) ok = false;
        for(int i = I + 1;i < N;i++) if(a[i] > a[i - 1]) ok = false;
        cout<< (ok ? "YES" : "NO") << nl;
    }
}

