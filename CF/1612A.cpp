/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';

void solve()
{
    int a,b; cin>> a >> b;
    int dis = a + b;
    for(int i = 0;i <= 50;i++){
        for(int j = 0;j <= 50;j++){
            int ac = i + j;
            int bc = abs(a - i) + abs(b - j);
            if(dis == ac*2 && dis == bc * 2){
                cout<< i << ' ' << j << nl;
                return;
            }
        }
    }
    cout<< -1 << ' ' << -1 << nl;
}
int main()
{
    int T; cin>> T;
    while(T--)
    {
        solve();
    }
}
