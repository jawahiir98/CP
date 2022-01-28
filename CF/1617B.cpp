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
        if(N % 2 == 0){
            cout<< 2 << ' ' << N - 3 << ' ' << 1  << nl;
            //cout<< __gcd(2, N - 3) + N - 3 + 2 << nl;
        }
        else{
            if((N / 2) % 2 == 0) cout<< (N / 2) + 1 << ' ' << (N / 2) - 1 << ' ' << 1 << nl;
            else cout<< (N / 2) + 2 << ' ' << (N / 2) - 2 << ' ' << 1 << nl;
        }
    }
}
