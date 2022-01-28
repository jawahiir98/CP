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
    string s; cin>> s;
    int N = s.size();
    for(int x = 0;x < 10;x++){
        for(int y = 0;y < 10;y++){
            vector <vector <int>> dis(10, vector<int> (10, 1e9));
            for(int i = 0;i < 10;i++){
                dis[i][(x + i) % 10] = 1;
                dis[i][(y + i) % 10] = 1;
            }
            for(int k = 0;k < 10;k++){
                for(int i = 0;i < 10;i++){
                    for(int j = 0;j < 10;j++){
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    }
                }
            }
            ll rs = 0;
            for(int i = 0;i < N;i++){
                if(i == 0){
                    rs += s[i] == '0' ? 0 : dis[0][s[i] - '0'];
                }else{
                    rs += dis[s[i -1] - '0'][s[i] - '0'] - 1;
                }
            }
            if(rs >= 1e8) cout<< -1 <<  ' ';
            else cout<< rs << ' ';
        }
        cout<< nl;
    }
}
