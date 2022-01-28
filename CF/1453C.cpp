/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 2e3 + 100;

char a[E][E];
int main()
{
    int T; cin>> T;
    while(T--)
    {
        int N; cin>> N;
        vector <int> mxr(10, 0),mnr(10, 1e9),mxc(10, 0),mnc(10, 1e9);
        for(int i = 1;i <= N;i++){
            for(int j = 1;j <= N;j++){
                cin>> a[i][j];
                int x = a[i][j] - '0';
                mxr[x] = max(mxr[x], i); mnc[x] = min(mnc[x], j);
                mnr[x] = min(mnr[x], i); mxc[x] = max(mxc[x], j);
            }
        }
        vector <int> ans(10, 0);
        for(int i = 1;i <= N;i++){
            for(int j = 1;j <= N;j++){
                int x = a[i][j] - '0';
                ans[x] = max(ans[x], max(j - 1, N - j) * max(mxr[x] - i, i - mnr[x]));
                ans[x] = max(ans[x], max(i - 1, N - i) * max(mxc[x] - j, j - mnc[x]));
            }
        }
        for(int i = 0;i < 10;i++) cout<< ans[i] << ' ';
        cout<< nl;
    }
}
