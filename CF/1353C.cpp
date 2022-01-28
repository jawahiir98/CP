/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
#define bound(i, j) (i >= 0 and i < N and j >= 0 and j < N)
using namespace std;
typedef long long ll;
const char nl = '\n';

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main()
{
    int T; cin>>T;
    while(T--)
    {
        int N; cin>> N;
        ll ans = 0,cnt = N/2;
        while(cnt){
            ll M = 4 * N - 4;
            ans += M * cnt;
            N -= 2;
            //cout<< N << ' ' << M << ' ' << ans << ' ' << cnt << nl;
            cnt--;
        }
        cout<< ans << nl;
    }
}
