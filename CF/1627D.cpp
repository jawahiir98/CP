/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int MAX = 1e6 + 10;

int main()
{
   int N; cin>> N;
   vector <int> a(N),have(E, 0);
   for(int i = 0;i < N;i++) cin>> a[i],have[a[i]] = 1;
   int M = *max_element(a.begin(),a.end());
   vector <int> pos(M + 2, 0);
   int ans = 0;
   for(int i = 1;i <= M;i++){
    if(have[i]){
        int g = 0;
        for(int j = i;j <= M;j += i){
            g = __gcd(g, j / i);
        }
    }
   }
}
