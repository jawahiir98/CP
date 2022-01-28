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
        vector <int> a(N + 1);
        priority_queue <pair<int, int>> p;
        p.push({N, 0});
        for(int x = 1;x <= N;x++)
        {
            auto [l, r] = p.top(); p.pop();
            int i = -r;
            int j = l + i;
            int M = (i + j - 1)/2;
            a[M] = x;
            p.push({M - i, -i});
            p.push({j - (M + 1), -(M + 1)});;
        }
        for(int i = 1;i <= N;i++) cout<< a[i - 1] << ' ';
        cout<< nl;
    }
}
