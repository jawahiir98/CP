/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 1e4 + 10;

void print(int a,int b,int c)
{
    while(a--) cout<< '1';
    cout<< "33";
    while(c > 0) c--,cout<< '7';
    while(b > 0) b--,cout<< '3';
    puts("7");
}
void solve()
{
    int N; cin>> N;
    int a = 1,b = 2,c = 1;
    while((b * (b + 1))/2 <= N) b++;
    c = N - (b * (b - 1))/2;
    //cout<< a << ' ' << b << ' ' << c << nl;
    print(a, b - 2, c);
}
int main()
{
    int T; cin>> T;
    while(T--)
    {
        solve();
    }
}
