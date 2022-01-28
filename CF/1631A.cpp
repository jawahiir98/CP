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
        vector <int> a(N),b(N);
        for(int i = 0;i < N;i++) cin>> a[i];
        for(int i = 0;i < N;i++) cin>> b[i];
        int A = *max_element(a.begin(), a.end());
        int B = *max_element(b.begin(), b.end());
        if(A >= B){
            for(int i = 0;i < N;i++){
                if(b[i] > a[i]) swap(a[i], b[i]);
            }

        }
        else{
            for(int i = 0;i < N;i++){
                if(a[i] > b[i]) swap(a[i], b[i]);
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        cout<< a[N - 1] * b[N - 1] << nl;
    }
}
