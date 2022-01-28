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
    int T; cin>>T ;
    while(T--)
    {
        int N,K; cin>> N >> K;
        if(N < K) cout<< K - N << nl;
        else if(N % 2 == K % 2) cout<< 0 << nl;
        else cout<< 1 << nl;
    }
}
