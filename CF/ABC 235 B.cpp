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
    int res = a[0];
    for(int i = 1;i < N;i++){
        if(a[i] > a[i - 1]) res = a[i];
        else break;
    }cout<< res << nl;
}
