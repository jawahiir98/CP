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
        for(int i = 0;i < N;i++){
            cin>> a[i];
        }
        int cnt = 0;
        for(int i = 1;i < N;i++){
            if(a[i] > a[i - 1]) a[i] = a[i - 1];
        }
        bool ok = true;
        for(int i = 0;i < N - 1;i++){
            int x = a[i];
            for(int j = i + 1;j < N;j++){
                x += a[j];
                if(2 * x != (a[i] + a[j])* (j - i + 1)){
                    int y = (2 * x) - (a[i] + a[j]);
                    a[i] = (a[i] + y) * (j - i + 1);
                    cnt++;
                }
            }
        }
        for(int i = 0;i <N;i++) cout<< a[i] << ' ';
        cout<< cnt << nl;
    }
}
