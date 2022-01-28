/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 3e5 + 10;

int main()
{
    int T; cin>> T;
    while(T--)
    {
        int N; cin>> N;
        vector <int> a(N),cnt(N + 1, 0);
        for(int i = 0;i < N;i++){
            cin>> a[i];
            cnt[a[i]] += 1;
        }
        int l = 0,r = N - 1;
        vector <int> ans(N, 0);
        for(int k = 1;k < N;k++){
            if(cnt[k] == 0) break;
            ans[N - k] = 1;
            if((a[l] != k and a[r] != k) || cnt[k] != 1) break;
            if(a[l] == k) l++;
            else  r--;
        }
        bool first = true;
        for(int i = 1;i <= N;i++) if(cnt[i] != 1) first = false;
        ans[0] = first;
        for(int x : ans) cout<< x;
        cout<< nl;
    }
}
