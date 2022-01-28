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
        int N,K; cin>> N >> K;
        vector <int> a(N, 0);
        iota(a.begin(), a.end(), 0);
        if(K == N - 1 and N == 4) puts("-1");
        else if(K == N - 1)
        {
            vector <pair<int,int>> r;
            r.pb({0, 2});
            r.pb({N - 1, N - 2});
            r.pb({1, N - 3});
            int ans = 0;
            for(int i = 3,j = N - 4;i < N/2;i++,j--) r.pb({i, j}),ans += (i & j);
            ans += (0 &(N - 3)) + ((N - 1) & (N - 2)) + (1 & 2);
            for(auto [x, y] : r) cout<< x << ' ' << y << nl;
            //cout<< ans << nl;
        }
        else{
            vector <pair<int, int>> r;
            for(int i = 0,j = N - 1;i < N/2;i++,j--) r.pb({i, j});
            //for(auto [x,y]: r) cout<< x << ' ' << y << nl;
            for(int i = 0;i < N/2;i++){
                if(r[i].first == K){
                     swap(r[0].first, r[i].first);
                     break;
                }
                else if(r[i].second == K){
                    swap(r[0].first, r[i].second);
                    break;
                }
            }
            for(auto [x, y] : r) cout<< x << ' ' << y << nl;
        }
    }
}
