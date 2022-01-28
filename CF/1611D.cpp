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
        vector <int> b(N + 1),p(N + 1),dis(N + 1, -1);
        for(int i = 1;i <= N;i++) cin>> b[i];
        for(int i = 1;i <= N;i++) cin>> p[i];
        bool ok = true;
        if(b[p[1]] != p[1]) ok = false;
        dis[p[1]] = 0;
        for(int i = 2;i <= N;i++){
            if(dis[b[p[i]]] == -1){
                ok = false;
                break;
            }
            dis[p[i]] = dis[p[i - 1]] + 1;
        }
        if(!ok) cout<< -1;
        else for(int i = 1;i <= N;i++) cout<< dis[i] - dis[b[i]] << ' ';
        cout<< nl;
    }
}
