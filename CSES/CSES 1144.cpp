/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
const char nl = '\n';
const int MOD = 1e9 + 10;

int main()
{
    int N,Q; cin>> N >> Q;
    vector <int> a(N + 1);
    Tree <pair<int, int>> s;
    for(int i = 1;i <= N;i++){
        cin>> a[i];
        s.insert({a[i], i});
    }
    while(Q--)
    {
        char c; cin>> c;
        if(c == '?'){
            int a,b; cin>> a >> b;
            cout<< s.order_of_key({b, MOD}) - s.order_of_key({a - 1, MOD}) << nl;
        }else{
            int pos,val; cin>> pos >> val;
            s.erase({a[pos], pos});
            a[pos] = val;
            s.insert({a[pos], pos});
        }
    }
}
