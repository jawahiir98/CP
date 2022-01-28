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
        int N,K; cin>> N >> K;
        if(K > N - N/2) puts("-1");
        else{
            char a[N + 1][N + 1];
            for(int i = 0;i < N;i++)
                for(int j = 0;j < N;j++) a[i][j] = '.';
            for(int i = 0;i < N;i += 2){
                 if(!K) break;
                 a[i][i] = 'R';
                 K--;
            }
            for(int i = 0;i < N;i++){
                for(int j = 0;j < N;j++) cout<< a[i][j];
                cout<< nl;
            }
        }
    }
}
