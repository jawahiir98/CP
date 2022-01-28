/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 1e6 + 43242;

int main()
{
    int a,N; cin>> a >> N;
    vector <int> dis(E + 10, -1);
    queue <ll> q;
    dis[1] = 0;
    q.push(1);
    while(!q.empty())
    {
        ll u = q.front();
        if(u == N) break;
        q.pop();
        ll v = u * a;
        if(v < E and dis[v] == -1){
            dis[v] = dis[u] + 1;
            q.push(v);
        }
        if(u >= 10 and u % 10 != 0)
        {
            string p = to_string(u);
            p = p[(int)p.size() - 1] + p.substr(0, (int)p.size() - 1);
            v = stoi(p);
            if(v < E and dis[v] == -1)
            {
                dis[v] = dis[u] + 1 ;
                q.push(v);
            }
        }
    }
    cout<< dis[N] << nl;
}
