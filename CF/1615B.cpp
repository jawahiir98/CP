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

int col[E][33];
int main()
{
    for(int i = 1;i < E;i++){
        int x = i,j = 0;
        while(x){
            col[i][j++] = (x % 2 == 1);
            x /= 2;
        }
    }
    for(int i = 0;i < 33;i++){
        for(int j = 1;j < E;j++){
            col[j][i] += col[j - 1][i];
        }
    }
    int T; cin>> T;
    while(T--)
    {
        int l,r; cin>> l >> r;
        int res = 0;
        for(int i = 0;i < 33;i++){
            res = max(res, col[r][i] - col[l - 1][i]);
        }
        cout<< (r - l + 1) -  res << nl;
    }
}
