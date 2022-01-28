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
    int N,M; cin>> N >> M;
    vector <vector<int>> a(N + 1, vector<int>(N + 1, 0));
    vector <vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    for(int i = 1;i <= N;i++)
        for(int j = 1;j <= N;j++){char c; cin>> c; if(c != '.') a[i][j] = 1;}
    for(int i = 1;i <= N;i++){
        for(int j = 1;j <= N;j++){
            dp[i][j] = a[i][j];
        }
    }
    for(int i = 1;i <= N;i++){
        for(int j = 1;j <= N;j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
            //cout<< dp[i][j] << ' ';
        } //cout<< nl;
    }
    while(M--)
    {
        int a,b,l,r; cin>> a >> b >> l >> r;
        cout<< dp[l][r] - dp[a - 1][r] - dp[l][b - 1] + dp[a - 1][b - 1] << nl;
    }
}
