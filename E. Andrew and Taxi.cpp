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
int n,m;
vector<ii>G[tam];
vector<pair<ii,int> > E;
vi color;
vi res;
bool dfs(int nodo, int ant, int mid){
    color[nodo]=1;
    for(auto v:G[nodo]){
        if(v.S<=mid)continue;
        if(color[v.F]==1){
            return false;
        }
        if(color[v.F]==0){
            if(!dfs(v.F,nodo,mid))return false;
        }
    }
    color[nodo]=2;
    return true;
}
bool ok(int mid){
    //are there cycles
    color.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(color[i]==0){
            if(!dfs(i,-1,mid))return false;
        }
    }
    return true;    
}
void buildTopo(int nodo, int ant, int mid, vi &topo){
    color[nodo]=1;
    for(auto v:G[nodo]){
        if(v.S<=mid)continue;
        if(color[v.F]==1){
            continue;
        }
        if(color[v.F]==0){
            buildTopo(v.F,nodo,mid,topo);
        }
    }
    color[nodo]=2;
    topo.pb(nodo);
}
void build(int mid){
    color.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(color[i]==0){
            buildTopo(i,-1,mid,res);
        }
    }
    reverse(all(res));
}
signed main()
{
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        E.pb({{a,b},c});
        
        G[a].pb({b,c});
    }  
    b=0;
    int e=1e9;
    int mejor=0;
    
    while(b<=e){
        int mid=(b+e)/2;
        if(ok(mid)){
            mejor=mid;
            e=mid-1;
        }else{
            b=mid+1;
        }
    }
    
    build(mejor);
    int pos[n+5];
    for(int i=0;i<res.size();i++){
        // cout<<res[i]<<" ";
        pos[res[i]]=i;
    }
    // cout<<endl;
    
    vi ans;
    for(int i=0;i<m;i++){
        a=E[i].F.F;
        b=E[i].F.S;
        c=E[i].S;
        if(c>mejor)continue;
        if(pos[a]>pos[b]){
            ans.pb(i+1);
        }
    }
    
    cout<<mejor<<" "<<ans.size()<<endl;
    for(auto v:ans)cout<<v<<" ";


    int res=0;
    return 0;
}
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA YES OR YES?
// https://codeforces.com/problemset/problem/1100/E