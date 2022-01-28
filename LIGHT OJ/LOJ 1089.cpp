/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 5e4 + 101;

int main()
{
    int T,cs = 0; scanf("%d", &T);
    while(T--)
    {
        int N,Q; scanf("%d%d", &N, &Q);
        vector <pair<int, int>> a(N);
        vector <int> points;
        for(int i = 0;i < N;i++){
            scanf("%d%d", &a[i].first, &a[i].second);
            points.pb(a[i].first);
            points.pb(a[i].second);
        }
        vector <int> queries(Q);
        for(int i = 0;i < Q;i++){
            scanf("%d", &queries[i]);
            points.pb(queries[i]);
        }
        sort(points.begin(), points.end());
        int cnt = 1;
        map <int, int> mp;
        for(int i = 0;i < points.size();i++){
            if(mp.find(points[i]) == mp.end()) mp[points[i]] = cnt++;
        }
        vector <int> sum(cnt + 1, 0);
        for(int i = 0;i < N;i++){
            int l = mp[a[i].first];
            int r = mp[a[i].second];
            sum[l] += 1;
            sum[r + 1] -= 1;
        }
        for(int i = 1;i <= cnt;i++) sum[i] += sum[i - 1];
        printf("Case %d:\n",++cs);
        for(int i = 0;i < Q;i++){
            printf("%d\n", sum[mp[queries[i]]]);
        }
    }
}
