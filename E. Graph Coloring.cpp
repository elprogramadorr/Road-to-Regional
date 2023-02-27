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

const int tam=5005;
vi G[tam];
int vis[tam];
int dp[tam][tam];
int color[tam];
int A=0;
int B=0;
bool bipartite(int nodo, int c){
    if(vis[nodo]!=-1){
        return vis[nodo]==c;
    }
    if(c){
        A++;
    }else{
        B++;
    }
    vis[nodo]=c;
    
    for(auto it : G[nodo]){
        if(!bipartite(it,!c))return false;
    }
    return true;
}
vi v1,v2;
int n1,n2,n3; 
int pref[tam];
int f(int pos, int cant, int resta){
    if(pos==v1.size())return true;
    if(dp[pos][cant]!=-1){
        return dp[pos][cant];
    }
    dp[pos][cant]=2;
    if(cant>=v1[pos] && resta>=v2[pos]){
        dp[pos][cant]=f(pos+1,cant-v1[pos],resta-v2[pos]);
    }
    if(dp[pos][cant]!=2){
        dp[pos][cant]=0;
        return 1;
    }
    if(cant>=v2[pos] && resta>=v1[pos]){
        dp[pos][cant]=f(pos+1,cant-v2[pos],resta-v1[pos]);
    }
    if(dp[pos][cant]!=2){
        dp[pos][cant]=1;
        return 1;
    }
    return dp[pos][cant];
}
bool vis2[tam];
void build(int nodo, int tipo){

    if(tipo==0){
        if(vis[nodo]==1){
            color[nodo]=2;
        }else{
            if(n1){
                color[nodo]=1;
                n1--;
            }else{
                color[nodo]=3;
                n3--;
            }
        }
    }else{
        if(vis[nodo]!=1){
            color[nodo]=2;
        }else{
            if(n1){
                color[nodo]=1;
                n1--;
            }else{
                color[nodo]=3;
                n3--;
            }
        }
    }
    for(auto it : G[nodo]){
        if(color[it])continue;
        build(it,tipo);
    }
}

signed main(){
    fast;
    memset(vis,-1,sizeof(vis));
    memset(dp,-1,sizeof(dp));
    int n,m,a,b;
    cin>>n>>m;
    cin>>n1>>n2>>n3;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        // cout<<a<<"  unido  "<<b<<endl;
        G[a].pb(b);
        G[b].pb(a);
    }   
    vi NODO;
    for(int i=1;i<=n;i++){
        if(vis[i]!=-1)continue;
        NODO.pb(i);
        A=0,B=0;
        if(!bipartite(i,1)){
            cout<<"NO"<<endl;
            return 0;
        }
        v1.pb(A);v2.pb(B);
    }
    if(f(0,n2,n1+n3)==2){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    int pos=0;
    int cant=n2;
    while(pos<v1.size()){
        int gaste2=n2-cant;
        int Q=0;if(pos)Q=pref[pos-1];
        int resta=n1+n3-(Q-gaste2);
        build(NODO[pos],dp[pos][cant]);
        if(dp[pos][cant]==0){
            //cant con v1
            cant-=v1[pos];
        }else{
            cant-=v2[pos];
        }
        pos++;
    }
    for(int i=1;i<=n;i++){
        cout<<color[i];
    }

    
    return 0;
}
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA YES OR YES?
// https://codeforces.com/contest/1354/problem/E