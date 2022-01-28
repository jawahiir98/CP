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
        vector <pair<int, int>> a(N);
        for(int i = 0;i < N;i++) cin>> a[i].first >> a[i].second;
        set <int> s;
        for(int i = 1;i <= N;i++) s.insert(i);
        vector <int> res(N + 1, 0),taken(N + 1, 0);
        for(int i = 0;i < N;i++){
            int x = -1,tmp = 1e9;
            for(int j = 0;j < N;j++){
                if(a[j].second - a[j].first < tmp && res[j] == 0){
                    tmp = a[j].second - a[j].first;
                    x = j;
                }
            }
            for(int j = a[x].first;j <= a[x].second;j++){
                if(taken[j] == 0){
                    res[x] =  j;
                    taken[j] = 1;
                    break;
                }
            }
        }
        for(int i = 0;i < N;i++){
            cout<< a[i].first << ' ' << a[i].second << ' ' << res[i] << nl;
        }
    }
}
