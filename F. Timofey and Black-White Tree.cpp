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
#define lcm(a,b) (a/__gcd(a,b))*b
#define jumanji ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define ll long long
using namespace std;
vi depth;
int res=1e9;
vector<vi> adj;
void dfs(int nodo, int ant, int d){
    res=min(res,depth[nodo]+d);
    if(depth[nodo]<d)return;
    if(d>res)return;
    depth[nodo]=min(depth[nodo],d);
    for(int i=0;i<adj[nodo].size();i++){
        int v=adj[nodo][i];
        if(v==ant)continue;
        dfs(v,nodo,d+1);
    }
}
int main()
{
    jumanji
    int t,n,x,y;
    cin>>t;
    while(t--){
        cin>>n;
        adj.assign(n+1,vi());
        depth.assign(n+1,n+5);
        res=1e9;
        vi v;
        int I;
        cin>>I;
        for(int i=0;i<n-1;i++){
            cin>>x;
            v.pb(x);
        }
        for(int i=0;i<n-1;i++){
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        dfs(I,-1,0);
        for(int i=0;i<n-1;i++){
            dfs(v[i],-1,0);
            cout<<res<<" ";
        }
        cout<<"\n";
    }    
    
    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?