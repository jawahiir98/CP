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
        string s; cin>> s;
        int N = s.size();
        int I = -1,M = -1;
        for(int i = 0;i < N - 1;i++){
            int n = s[i] - '0' + s[i + 1] - '0';
            if(n >= 10){
                I = i;
                M = n;
            }
        }
        if(M >= 10){
            for(int i = 0;i < N;i++){
                if(i == I){
                    cout<< M;
                    i++;
                    continue;
                }
                cout<< s[i];
            }
            cout<< nl;
        }
        else{
            cout<< s[0] - '0' + s[1] - '0';
            for(int i = 2;i < N;i++) cout<< s[i];
            cout<< nl;
        }
    }
}
