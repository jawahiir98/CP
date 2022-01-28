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
        vector <int> a(N);
        for(int i = 0;i < N;i++){
            cin>> a[i];
        }
        bool same = (a[0] == a[N - 1]);
        if(K == 1 && !same){
            cout<< -1 << nl;
            continue;
        }
        else if(same){
            cout<< 1 << nl;
            continue;
        }
        set <int> s;
        for(int i = 0;i < N;i++) s.insert(a[i]);
        int cnt = 1,n = s.size() - K;
        cnt += (n + K - 2) / (K - 1) ;
        cout<< cnt << nl;
    }
}
