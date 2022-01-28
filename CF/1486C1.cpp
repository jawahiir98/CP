/*
    /\ In The Name Of Allah /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const char nl = '\n';

int query(int l, int r)
{
    //assert(l < r);
    cout<< "? " << l << ' ' << r << endl;
    int a; cin>> a;
    return a;
}
int main()
{
    int N; cin>> N;
    int res = -1;
    int pos = query(1, N);
    if(pos != 1 and query(1, pos) == pos){
        int l = 1,r = pos - 1,M;
        while(l <= r)
        {
            M = (l + r)/2;
            if(query(M, pos) == pos) l = M + 1,res = M;
            else r = M - 1;
        }
    }
    else{
        int l = pos + 1,r = N,M;
        while(l <= r)
        {
            M = (l + r)/2;
            if(query(pos, M) == pos) r = M - 1,res = M;
            else l = M + 1;
        }
    }
    cout<< "! " << res << nl;
}
