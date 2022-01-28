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
        int M,N; cin>> M >> N;
        vector <vector<int>> a(M, vector <int>(N));
        for(int i = 0;i < M;i++)
            for(int j = 0;j < N;j++) cin>> a[i][j];
        auto pos = [&](int x)
        {
            int shop = 0;
            for(int j = 0;j < N;j++){
                bool ok = false;
                for(int i = 0;i < M;i++){
                    if(a[i][j] >= x){
                        ok = true;
                        break;
                    }
                }
                shop += ok;
            }
            if(shop < N) return false;
            for(int i = 0;i < M;i++){
                int cnt = 0;
                for(int j = 0;j < N;j++) cnt += a[i][j] >= x;
                if(cnt > 1) return true;
            }
            return false;
        };
        int l = 0,r = 1e9 + 10,Mid;
        while(l <= r)
        {
            Mid = (l + r)/2;
            if(pos(Mid)){
                l = Mid + 1;
            }
            else r = Mid - 1;
        }
        cout<< r << nl;
    }
}
