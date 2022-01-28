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
        reverse(a.begin(), a.end());
        int done = 0,cnt = 0;
        for(int i = 0;i < N;){
            if(a[i] == a[0]){
                done++;
                ++i;
                continue;
            }else{
                i *= 2;
                cnt++;
            }
        }
        cout<< cnt << nl;
    }
}
