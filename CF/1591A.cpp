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
        for(int i = 0;i <  N;i++) cin>> a[i];
        int cons = 0,di = 0,ans = 1;
        for(int i = 0;i < N;){
            if(a[i] == 1){
                ans += 1;
                while(i < N && a[i] == 1){
                    cons++;
                    i++;
                }
                ans += (cons - 1) * 5;
                cons = 0;
            }
            else{
                while(i < N && a[i] == 0){
                    di++;
                    i++;
                }
                if(di >= 2) break;
                di = 0;
            }
        }
        cout<<(di >= 2 ? -1 : ans) << nl;
    }
}
