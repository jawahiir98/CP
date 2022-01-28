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
    int N,Q; cin>> N >> Q;
    vector <int> a(N);
    map <int, int> mp;
    map <pair<int, int>, int> cnt;
    for(int i = 0;i < N;i++){
        cin>> a[i];
        mp[a[i]] = 1;
    }
    for(int i = 0;i < N;i++){
        int x = mp[a[i]];
        cnt[{a[i], x}] = i + 1;
        mp[a[i]] = x + 1;
    }
    while(Q--){
        int x,oc; cin>> x >> oc;
        if(cnt.find({x, oc}) != cnt.end()) cout<< cnt[{x, oc}] << nl;
        else cout<< -1 << nl;
    }
}
