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
        int mx = *max_element(a.begin(), a.end());
        int lst = a[N - 1],res = 0;
        for(int i = N - 1;i >= 0;i--){
            if(lst == mx){
                break;
            }
            else if(a[i] > lst){
                lst = a[i];
                res++;
            }
        }
        cout<< res << nl;
    }
}
