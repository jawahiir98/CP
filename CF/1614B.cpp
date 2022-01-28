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
        vector <pair<int, int>> a(N);
        vector <int> tmp(N);
        for(int i = 0;i < N;i++){
            cin>> a[i].first;
            a[i].second = i;
            tmp[i] = a[i].first;
        }
        sort(a.begin(),a.end());
        vector <int>  pos(N + 1);
        pos[0] = 0;
        ll res = 0;
        for(int dir = 1,l = 1,i = N - 1;i >= 0;i--){
            pos[a[i].second + 1] = dir * l;
            dir *= -1;
            if(dir > 0) l++;
        }
        for(int i = 1;i <= N;i++){
            res +=  2LL * abs(pos[0] - pos[i]) * tmp[i - 1];
        }
        cout<<res << nl;
        for(auto x : pos) cout<< x << ' ';
        cout<< nl;
    }
}
