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
        int N,K; cin>> N >> K;
        vector <int> a(N),b(N);
        for(int i = 0;i < N;i++) cin>> a[i];
        for(int i = 0;i < N;i++) cin>> b[i];
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        for(int i = 0,j = 0,k = 0;i < N and k < K;i++){
            if(a[i] < b[j]){
                swap(a[i], b[j]);
                k++;
                j++;
            }
        }
        ll S = 0;
        for(int i = 0;i < N;i++) S += a[i];
        cout<< S << nl;
    }
}
