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
    vector <pair<ll, ll>> a(N);
    for(int i = 0;i < N;i++) cin>> a[i].second >> a[i].first;
    sort(a.begin(), a.end());
    ll res = 0,i = 0,j = N - 1,cur = 0;
    while(i <= j){
        ll need = a[i].first - cur;
        if(need <= 0){
            res += a[i].second;
            cur += a[i].second;
            i++;
            continue;
        }
        if(need >= a[j].second){
            res += 2 * a[j].second;
            cur += a[j].second;
            j--;
            continue;
        }
        else{
            res += 2 * need;
            cur += need;
            a[j].second -= need;
        }
    }
    cout<< res << nl;
}
