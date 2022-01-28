/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 1e5 + 10;

int main()
{
    vector <int> p(E, 0),t;
    for(int i = 2;i * i <= E;i++){
        if(!p[i]){
            for(int j = i + i;j < E;j += i) p[j] = 1;
        }
    }
    for(int i = 2;i < E;i++) if(!p[i]) t.pb(i);
    int T; cin>> T;
    while(T--)
    {
        int N; cin>> N;
        int tar = t[N + 10];
        if(N == 2){
            puts("1 1");
            puts("1 1");
        }
        else{
            vector <int> out;
            out.pb(1);
            for(int i = 0;i < N - 2;i++){
                tar -= 4;
                out.pb(4);
            }
            out.pb(tar - 1);
            for(int i = 0;i < N;i++){
                for(int j = 0;j < N;j++) cout<< out[(i + j) % N] << ' ';
                cout<< nl;
            }
        }
    }
}
