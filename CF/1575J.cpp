/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 1e3 + 10;

int a[E][E];
int main()
{
    int T = 1;
    while(T--)
    {
        int N,M,K; cin>> N >> M >> K;
        for(int i = 1;i <= N;i++){
            for(int j = 1;j <= M;j++){
                cin>> a[i][j];
            }
        }
        vector <int> res(K + 1, 0);
        for(int i = 1;i <= K;i++){
            int y; cin>> y;
            int x = 1;
            while(x <= N){
                if(a[x][y] == 2){
                    x += 1;
                }
                else if(a[x][y] == 1){
                    a[x][y] = 2;
                    y += 1;
                }else{
                    a[x][y] = 2;
                    y -= 1;
                }
            }
            res[i] = y;
        }
        for(int i = 1;i <= K;i++) cout<< res[i] << ' ';
        cout<< nl;
    }
}
