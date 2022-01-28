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
    vector <int> a(N),b(N);
    for(int i = 0;i < N;i++){
        cin>> a[i];
    }
    for(int i = 0;i < N;i++){
        cin>> b[i];
    }
    int res = 0,cnt = 0;
    for(int i = 0,j = 0;i < N;i++){
        if(b[i] % a[j] == 0){
            res++;
            j++;
        }
    }
    for(int i = 0,j = 0;j < N;j++){
        if(b[i] * 2 >= N && b[i] % a[j]){
            ++i;
            continue;
        }
        if(b[i] % a[j] == 0){
            cnt++;
            i++;
        }
    }
    cout<< res << ' ' << cnt << nl;
}
