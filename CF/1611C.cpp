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
        if(a[0] != N && a[N - 1] != N) cout<< -1 << nl;
        else{
            deque <int> d;
            for(int i = 0,j = N - 1;i <= j;i++,j--){
                if(i == j){
                    d.push_front(a[i]);
                    break;
                }
                d.push_front(a[i]);
                d.push_back(a[j]);
            }
            for(auto i : d) cout<< i << ' ';
            cout<< nl;
        }
    }
}
