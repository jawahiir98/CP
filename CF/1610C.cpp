
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
        //sort(a.begin(), a.end());
        auto can = [&](int x)
        {
            int cnt = 0;
            for(int i = 0;i < N;i++){
                if(cnt <= a[i].second && x - a[i].first - 1 <= cnt) cnt++;
            }
            return cnt >= x;
        };
        int l = -1,r = N + 1,Mid;
        while(l <= r)
        {
            Mid = (l + r)/2;
            if(can(Mid)) l = Mid + 1;
            else r = Mid - 1;
        }
        cout<< r << nl;
    }
}
