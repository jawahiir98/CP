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
        vector <int> a(N),pos(N + 1, 0);
        for(int i = 0;i < N;i++) cin>> a[i],pos[a[i]] += 1;
        int mex = -1;
        for(int i = 0;i <= N;i++){
            if(!pos[i]){ mex = i; break;}
        }
        bool ok = false;
        ll cnt = 0;
        priority_queue <int> p;
        for(int i = 0;i <= N;i++){
            if(ok) cout<< -1 << ' ';
            else cout<< cnt + pos[i] << ' ';
            for(int j = 0;j < pos[i];j++){
                p.push(i);
            }
            if(p.empty()) ok = true;
            else{
                cnt += i - p.top();
                p.pop();
            }
        }
        cout<< nl;
    }
}
