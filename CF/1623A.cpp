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
        int N,M,a,b,x,y; cin>> N >> M >> a >> b >> x >> y;
        int ans = 0;
        int dx = 1,dy = 1;
        while(a != x && y != b)
        {
            if(a == N) dx *= -1;
            if(b == M) dy *= -1;
            a += dx,b += dy,ans += 1;
        }
        cout<< ans << nl;
    }
}
