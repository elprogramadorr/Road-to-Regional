#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <bits/stdc++.h>
#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define F first
#define S second
#define int long long
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int tam=100005;
bool vis[tam];
int P[2][tam];
int _find(int nodo, bool who){
    if(P[who][nodo]==nodo)return nodo;
    return P[who][nodo]=_find(P[who][nodo],who);
}
bool _union(int a, int b, bool who){
    a=_find(a,who);
    b=_find(b,who);
    if(a==b)return false;
    P[who][a]=b;
    return true;
}
signed main(){
    int n,m,a,b;
    cin>>n>>m;
    char c;
    vector<pair<ii,int> >A,B;

    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(c=='S'){
            A.pb({{a,b},i});
        }else{
            B.pb({{a,b},i});
        }
    }
    for(int i=1;i<=n;i++){
        P[0][i]=i;
        P[1][i]=i;
    }
    if((n-1)%2!=0){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<A.size();i++){
        int a=A[i].F.F;
        int b=A[i].F.S;
        _union(a,b,0);
    }
    int cant=0;
    for(int i=1;i<=n;i++){
        if(P[0][i]==i)cant++;
    }
    if(cant-1>(n-1)/2){
        cout<<-1<<endl;
        return 0;
    }
    int cuantos=0;
    for(int i=0;i<B.size();i++){
        int a=B[i].F.F;
        int b=B[i].F.S;
        int ind=B[i].S;
        if(_union(a,b,0)){
            _union(a,b,1);
            vis[ind]=true;
            cuantos++;
        }
    }
    for(int i=0;i<B.size() && cuantos<(n-1)/2;i++){
        int a=B[i].F.F;
        int b=B[i].F.S;
        int ind=B[i].S;
        if(vis[ind]==false && _union(a,b,1)){
            vis[ind]=true;
            cuantos++;
        }
    }
    if(cuantos<(n-1)/2){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<A.size();i++){
        int a=A[i].F.F;
        int b=A[i].F.S;
        int ind=A[i].S;
        if(vis[ind]==false && _union(a,b,1)){
            vis[ind]=true;
        }
    }
    cout<<n-1<<endl;
    for(int i=0;i<m;i++){
        if(vis[i])cout<<i+1<<" ";
    }
    cout<<"\n";

    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?
// https://codeforces.com/problemset/problem/141/E