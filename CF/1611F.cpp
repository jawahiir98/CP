/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 2e5 + 10;
int main()
{
    int T; cin>> T;
    while(T--)
    {
        int N,S; cin>> N >> S;
        vector <int> a(N);
        for(int i = 0;i < N;i++) cin>> a[i];
        int mn = *max_element(a.begin(), a.end());
        if(-1 * mn > S){
            cout<< -1 << nl;
            continue;
        }
        ll sum = S,L,R,l = 0,len = -1;
        for(int r = 0;r < N;r++){
            sum += a[r];
            if(a[r] < 0){
                while(sum < 0){
                    sum -= a[l++];
                }
            }
            if(len < r - l + 1) len = r - l + 1,L = l,R = r;
        }
        L++,R++;
        cout<< L << ' ' << R << nl;
    }
}
