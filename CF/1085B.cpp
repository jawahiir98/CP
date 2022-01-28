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
    int N,K; cin>> N >> K;
    int res = 1e9 + 10;
    for(int i = 1;i < K;i++){
        if(N % i == 0){
            res = min(i + (N / i) * K, res);
        }
    }
    cout<< res << nl;
}
