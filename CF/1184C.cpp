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
    int N; cin>> N;
    vector <pair<int, int>> a(N * 4 + 1);
    map <pair<int, int>, int> mp;
    for(int i = 0;i < 4 * N + 1;i++){
        cin>> a[i].first >> a[i].second;
    }
    // Left = 1,Right = 2,Up = 3,Down = 4
    int M = 4 * N + 1;
    for(int i = 0;i < M;i++){
        int mx = 1e9,nx = -1e9,my = 1e9,ny = -1e9;
       for(int j = 0;j < M;j++){
           if(i == j) continue;
           nx = max(nx, a[j].first);
           mx = min(mx, a[j].first);
           ny = max(ny, a[j].second);
           my = min(my, a[j].second);
       }
       if(mx - nx != my - ny) continue;
       bool inside = true;
       for(int j = 0;j < M;j++)
       {
            if(i == j) continue;
            auto [x, y] = a[j];
            if(nx != x and mx != x and my != y and ny != y){
                inside = false;
                break;
            }
       }
       if(inside){
         return cout<< a[i].first << ' ' << a[i].second, 0;
       }
    }
}
