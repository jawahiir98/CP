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
        vector <int> a(N);
        for(int i = 0;i < N;i++) cin>> a[i];
        sort(a.begin(), a.end());
        vector <int> pos(N + 1, 0),rem,cons;
        for(int i = 0;i < N;i++){
            if(a[i] <= N && pos[a[i]] == 0) pos[a[i]] = 1;
            else rem.pb(a[i]);
        }
        for(int i = 0;i < N;i++) if(pos[i + 1] == 0) cons.pb(i + 1);
        bool ok = true;
        int cnt = 0;
        for(int i = 0;i < rem.size();i++){
            //cout<< a[i] << ' ' << i + 1 << nl;
            if(rem[i] != cons[i]){
                if(rem[i] % (rem[i] - cons[i]) != cons[i]) ok = false;
                else cnt++;
            }
        }
        if(!ok){
            cout<< -1 << nl;
            continue;
        }
        cout<< cnt << nl;

    }
}
