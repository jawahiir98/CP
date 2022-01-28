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
        string s; cin>> s;
        vector <int> b(N + 2,0),c(N + 2, 0),a;
        for(int i = 0;i < N;i++){
            if(s[i] == 'a') a.pb(i + 1);
            else if(s[i] == 'b'){
                b[i + 1] = 1;
            }
            else c[i + 1] = 1;
        }
        for(int i = 1;i <= N + 1;i++) b[i] += b[i - 1],c[i] += c[i - 1];
        if(a.size() < 2) cout<< -1 << nl;
        else{
            int res = 1e9 + 10;
            for(int i = 1;i < a.size();i++){
                int x = b[a[i]] - b[a[i - 1] - 1];
                int y = c[a[i]] - c[a[i - 1] - 1];
                if(x < 2 && y < 2 && (x + y) <= 2) res = min(res, x + y + 2);
                if(i > 1){
                    int x = b[a[i]] - b[a[i - 2] - 1];
                    int y = c[a[i]] - c[a[i - 2] - 1];
                    if(x < 3 && y < 3 && (x + y) <= 8) res = min(res, x + y + 3);
                }
            }
            res = (res == 1e9 + 10 ? -1 : res);
            cout<< res << nl;
        }
    }
}
