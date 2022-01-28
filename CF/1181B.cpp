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

string Min_Num(string a,string b)
{
    if(a.size() == b.size()){
        for(int i = 0;i < a.size();i++){
            if(a[i] > b[i]) return b;
            else if(a[i] < b[i]) return a;
        }
    }else{
        if(a.size() > b.size()) swap(a, b);
        return a;
    }
}
string String_Sum(string x,string y)
{
    string ret = "";
    if(x.size() < y.size()) swap(x, y);
    int n1 = x.size(),n2 = y.size();
    for(int i = 0;i < n2;i++){
        x[n1 + i - n2] += y[i] - 48;
    }
    for(int i = n1 - 1;i >= 1;i--){
        if(x[i] > '9'){
            x[i] -= 10;
            x[i - 1]++;
        }
    }
    if(x[0] > '9') x[0] -= 10,x = '1' + x ;
    return x;
}
int main()
{
    int N; cin>> N;
    string s; cin>> s;
    int M = N / 2;
    while(s[M] == '0') M--;
    string res = s;
    if(M > 0) res = Min_Num(res, String_Sum(s.substr(0, M), s.substr(M)));
    M = (N + 1)/2;
    while(s[M] == '0') M++;
    if(M != N) res = Min_Num(res, String_Sum(s.substr(0, M), s.substr(M)));
    cout<< res << nl;
}
