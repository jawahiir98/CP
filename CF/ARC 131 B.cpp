/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';
const int E = 777;

int x[] = {-1, 0, 1, 0};
int y[] = {0, -1, 0, 1};
char s[E][E];
int a[E][E];
int main()
{
    int N,M; cin>> N >> M;

    for(int i = 1;i <= N;i++){
        for(int j = 1;j <= M;j++){
            cin>> s[i][j];
            if(s[i][j] == '.') s[i][j] = '6';
            a[i][j] = s[i][j] - '0';
        }
    }
    for(int i = 1;i <= N;i++){
        for(int j = 1;j <= M;j++){
            if(a[i][j] != 6) continue;
            vector <int> col(10, 0);
            for(int k = 0;k < 4;k++){
                col[a[i + x[k]][j + y[k]]] = 1;
            }
            for(int c = 1;c <= 5;c++){
                if(!col[c]){
                    a[i][j] = c;
                    break;
                }
            }
        }
    }
    for(int i = 1;i <= N;i++){
        for(int j = 1;j <= M;j++){
            cout<< a[i][j];
        }
        cout<< nl;
    }
}
