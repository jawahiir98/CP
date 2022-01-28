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
        vector <ll> ti(N),h(N);
        for(int i = 0;i < N;i++) cin>> ti[i];
        for(int i = 0;i < N;i++) cin>> h[i];
        for(int i = N - 2;i >= 0;i--) h[i] = max(h[i], h[i + 1] + ti[i] - ti[i + 1]);
        ll prev = 0,res = 0;
        prev = h[0];
        res = prev * (prev + 1)/2;
        for(int i = 1;i < N;i++){
            if(ti[i] - ti[i - 1] >= h[i]){
                res += h[i] * (h[i] + 1)/2;
                prev = h[i];
            }else{
                res -= prev * (prev + 1)/2;
                prev += (ti[i] - ti[i - 1]);
                res += prev * (prev + 1)/2;
            }
        }
        cout<< res << nl;
    }
}
