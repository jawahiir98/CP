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
        int N ; cin>> N;
        vector <int> a(N),b(N),t1,t2;
        for(int i = 0;i < N;i++){
            cin>> a[i];
        }
        for(int i = 0;i < N;i++){
            cin>> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i = 0;i < N;i++) a[i] += (a[i] != b[i]);
        if(a == b){
            cout<< "YES" << nl;
        }
        else cout<< "NO" << nl;
    }
}
