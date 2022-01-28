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
        ll N,M; cin>> N; M = N;
        ll ans = 0,turn = 1;
        while(N){
            if(N < 5){
                ans += turn == 1 ? max(1LL,N - 1) : 1;
                break;
            }
            if(N & 1 || (N / 2) % 2 == 0){
                ans += turn * 1;
                N -= 1;
                turn ^= 1;
            }else{
                ans += turn * N / 2;
                N /= 2;
                turn ^= 1;
            }
        }
        cout<< ans << nl;
    }
}
