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
        int N; cin>> N;
        vector <pair<int, int>> a(N),b(N);
        for(int i = 0;i < N;i++){
            cin>> a[i].first >> a[i].second;
            b[i] = {a[i].second, a[i].first};
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int res = 0;
        for(int i = 0;i < N;i++){
            int id,bd,L = i,R = N - 1;
            while(L <= R){
                int M = (L + R)/2;
                if(a[i].second >= a[M].first){
                    id = M;
                    L = M + 1;
                }else{
                    R = M - 1;
                }
            }
            L = 0,R = i;
            while(L <= R)
            {
                int M = (L + R)/2;
                if(a[i].first <= b[M].first){
                    bd = M;
                    R = M - 1;
                }else{
                    L = M + 1;
                }
            }
            //cout<< id << ' ' << bd << nl;
            res = max(res, id - bd + 1);
        }
        cout<< N - res << nl;
    }
}
