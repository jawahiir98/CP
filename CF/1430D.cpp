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
        string s; cin>> s;
        vector <int> a;
        int cnt = 0,tot = 0;
        for(int i = 0;i < N;){
            int j = i;
            while(j < N and s[i] == s[j]){
                j++;
                cnt++;
            }
            a.pb(cnt);
            cnt = 0;
            i = j;
        }
        int ans = 0,n = a.size();
        for(int i = 0;i < n;i++){
            ans = min(i + 1, ans + a[i] - 1);
        }
        ans += (n - ans + 1)/2;
        cout<< ans << nl;
    }
}
