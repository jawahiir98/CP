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
    int N; cin>> N;
    vector <int> a(N);
    int choto = 0,boro = 0;
    for(int i = 0;i < N;i++){
        cin>> a[i];
        if(a[i] < 0) choto++;
        else if(a[i] > 0)boro++;
    }
    if(N == 1){
        cout<< max(-a[0] - 1, a[0]) << nl;
        return 0;
    }
    if(N % 2 == 0){
        for(int i = 0;i < N;i++) {
            if(a[i] < 0) cout<< a[i] << ' ';
            else cout<< -a[i] - 1 << ' ';
        }
    }else{
        for(int i = 0;i < N;i++){
            if(a[i] >= 0) a[i] = -a[i] - 1;
        }
        int mn = 1e9 + 10,id = -1;
        for(int i = 0;i < N;i++){
            if(a[i] != -1 and mn > a[i]) mn = a[i], id = i;
        }
        if(id == -1) a[0] = 0;
        else a[id] = -a[id] - 1;
        for(int i = 0;i < N;i++){
            cout<< a[i] << ' ';
        }
    }
    return 0;
}
