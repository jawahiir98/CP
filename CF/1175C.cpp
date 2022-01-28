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
        int res = 1e9 + 101,dis = 1e9 + 10;
        for(int i = 0;i < N - K;i++){
            int cur = (a[i] + a[i + K])/2;
            int cur_dis = a[i + K] - a[i];
            if(cur_dis < dis){
                dis = cur_dis;
                res = cur;
            }
        }
        cout<< res << nl;
    }
}
