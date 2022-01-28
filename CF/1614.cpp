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
        int N,l,r,k; cin>> N >> l >> r >> k;
        vector <int> a(N);
        for(int i = 0;i <  N;i++) cin>> a[i];
        sort(a.begin(), a.end());
        int cnt = 0;
        for(int i = 0;i <  N;i++){
            if(a[i] >= l && a[i] <= r && a[i] <= k){
                cnt += 1;
                k -= a[i];
            }
        }
        cout<< cnt << nl;
    }
}
