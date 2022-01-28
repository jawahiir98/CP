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
        int N,M,d; cin>> N >> M;
        vector <int> res;
        for(int i = 0;i < N;i++){
            for(int j = 0;j < M;j++){
                int x = (max(i, N - 1 - i)+ max(j, M - 1 - j));
                res.pb(x);
            }
        }
        sort(res.begin(), res.end());
        for(auto x : res) cout<< x << ' ';
        cout<< nl;
    }
}
