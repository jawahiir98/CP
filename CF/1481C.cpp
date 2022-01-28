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
        int N,M; cin>> N >> M;
        vector <int> a(N),b(N),col(M),pos(M, 0);
        vector <int> paint[N + 1],can[N + 1];

        for(int i = 0;i < N;i++) cin>> a[i];
        for(int i = 0;i < N;i++) cin>> b[i];
        for(int i = 0;i < M;i++) cin>> col[i];

        for(int i = 0;i < N;i++){
            can[b[i]].pb(i);
            if(a[i] != b[i]){
                paint[b[i]].pb(i);
            }
        }
        bool ok = true;
        if(can[col[M - 1]].empty()) ok = false;
        for(int i = M - 1;i >= 0;i--){
            int c = col[i];
            if(!paint[c].empty()){
                int x = paint[c].back();
                paint[c].pop_back();
                pos[i] = x + 1;
            }
            else if(!can[c].empty()){ // If there exists a plank that is the same color.
                pos[i] = can[c].back() + 1;
            }else{
                pos[i] = pos[M - 1];
            }
        }
        for(int i = 1;i <= N;i++){
            if(!paint[i].empty()) ok = false;
        }
        cout<<(ok ? "YES" : "NO") << nl;
        if(ok){
            for(int i = 0;i < M;i++) cout<< pos[i] << ' ';
            cout<< nl;
        }
    }
}
