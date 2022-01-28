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
    vector <int> div[10020033];
    for(int i = 2;i <= 100000;i++){
        for(int j = i;j <= 100000;j += i){
            div[j].pb(i);
        }
    }
    int N; cin>> N;
    vector <int> a(N);
    for(int i =0;i < N;i++){
        cin>> a[i];
    }
}
