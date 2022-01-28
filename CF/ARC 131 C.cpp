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
    vector <int> a(N);
    for(int i = 0;i < N;i++) cin>> a[i];
    int rox = 0;
    for(int i = 0;i < N;i++) rox ^= a[i];
    if(N & 1) return cout<< "Win",0;
    else {
        for(int i = 0;i < N;i++) if(a[i] == rox) return cout<< "Win",0;
        cout<< "Lose" << nl;
    }
}
