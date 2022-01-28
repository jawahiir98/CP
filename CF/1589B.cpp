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
        int N,M; cin>> N >> M;
        if(N < M) swap(N , M);
        int ans = (N * M + 2)/3;
        cout<< ans << nl;
    }
}
