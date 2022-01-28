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
        for(int i = 0;i < N;i++){
            cin>> a[i];
        }
        int l,r;
        for(int i = 0,j = N - 1;i < j;i++,j--){
            if(a[i] != a[j]){
                l = a[i],r = a[j];
                break;
            }
        }
        vector <int> f,s;
        for(int i = 0;i < N;i++){
            if(a[i] != l) f.pb(a[i]);
        }
        for(int i = 0;i < N;i++){
            if(a[i] != r) s.pb(a[i]);
        }
        bool can = true;
        for(int i = 0,j = f.size() - 1;i < j;i++,j--){
            if(f[i] != f[j]) can = false;
        }
        if(can) goto skip;
        can = true;
        for(int i = 0,j = s.size() - 1;i <= j;i++,j--){
            if(s[i] != s[j]) can = false;
        }
        skip :
        cout<<(can ? "YES" : "NO") << nl;
        continue;
    }
}
