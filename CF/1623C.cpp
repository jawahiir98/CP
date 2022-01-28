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
        vector <ll> a(N);
        for(int i = 0;i < N;i++) cin>> a[i];
        auto can = [&](int x)
        {
            vector <ll> giv = a;
            for(int i = N - 1;i >= 2;i--){
                if(giv[i] < x) return false;
                ll move = min(a[i], giv[i] - x);
                ll d = move / 3;
                giv[i - 1] += d;
                giv[i - 2] += 2 * d;
                giv[i] -= 3 * d;
            }
            return *min_element(giv.begin(), giv.end()) >= x;
        };
        int l = 1,r = 1e9 + 10,M,res = 0;
        while(l <= r)
        {
            M = (l + r)/2;
            if(can(M)){
                l = M + 1;
                res = M;
            }else{
                r = M - 1;
            }
        }
        cout<< res << nl;
    }
}
