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
const int tam=200005;
int a[tam];
vi G[tam];
int f[tam];
set<int> F[tam];
//small to large dfs
void _find(int nodo, int ant){
    f[nodo]=a[nodo];
    if(ant!=-1)f[nodo]^=f[ant];
    for(auto it : G[nodo]){
        if(it!=ant){
            _find(it,nodo);
        }
    }
}
int res=0;
void dfs(int nodo, int ant){
    bool flag=false;
    F[nodo].insert(f[nodo]);
    for(auto it : G[nodo]){
        if(it==ant)continue;
        dfs(it,nodo);
        if(sz(F[nodo])<sz(F[it]))swap(F[nodo],F[it]);
        for(auto it2 : F[it]){
            if(F[nodo].count(a[nodo] ^ it2))flag=true;
        }
        for(auto it2 : F[it]){
            F[nodo].insert(it2);
        }
        F[it].clear();
    }
    if(flag){
        res++;
        F[nodo].clear();
    }
}
signed main()
{
    fast;
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    _find(1,-1);
    dfs(1,-1);
    cout<<res<<"\n";
    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?
// https://codeforces.com/problemset/problem/1709/E