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
vector<pair<int,char> >G[tam];
int vis[tam];
int n,m;
vi A,B;
bool dfs(int nodo, char c, int quiero){
    // cout<<nodo<<" "<<quiero<<endl;
    if(vis[nodo]!=-1){
        return vis[nodo]==quiero;
    }
    if(quiero){
        A.pb(nodo);
    }else{
        B.pb(nodo);
    }
    vis[nodo]=quiero;
    for(auto it : G[nodo]){
        char aux=it.S;
        if(c==aux){
            //toco ambos o ninguno
            if(!dfs(it.F,c,quiero))return false;
        }else{
            if(!dfs(it.F,c,!quiero))return false;
        }
    }
    return true;
}
vi go(char c){
    vi res;
    for(int i=1;i<=n;i++){
        A.clear();B.clear();
        if(vis[i]!=-1)continue;
        if(dfs(i,c,0)==false){
            for(int l=0;l<=n;l++){
                res.pb(1);
            }
            return res;
        }
        // cout<<A.size()<<" "<<B.size()<<endl;
        if(B.size()<A.size())swap(A,B);
        for(auto it : A){
            res.pb(it);
        }
    }
    return res;
}
signed main()
{
    fast;
    memset(vis,-1,sizeof(vis));
    int a,b;
    char c;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        G[a].pb({b,c});
        G[b].pb({a,c});
    }
    vi izq=go('R'); 
    
    memset(vis,-1,sizeof(vis));
    vi der=go('B');
    if(izq.size()>=n && der.size()>=n){
        cout<<-1<<endl;
        return 0;
    }
    if(der.size()>n){
        cout<<izq.size()<<endl;
        for(auto it : izq){
            cout<<it<<" ";
        }
        return 0;
    }
    if(izq.size()>n){
        cout<<der.size()<<endl;
        for(auto it : der){
            cout<<it<<" ";
        }
        return 0;
    }
    if(izq.size()<der.size()){
        cout<<izq.size()<<endl;
        for(auto it : izq){
            cout<<it<<" ";
        }
    }else{
        cout<<der.size()<<endl;
        for(auto it : der){
            cout<<it<<" ";
        }
    }
    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN
// https://codeforces.com/contest/662/problem/B