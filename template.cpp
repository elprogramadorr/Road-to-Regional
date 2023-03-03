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
#define int long long
#define vi vector<int>
#define ll long long
using namespace std;
const int tam=100005;
vi G[tam];
map<int,int> E[tam];
int v[tam];
int res=0;
void dfs(int nodo, int ant){
    E[nodo][v[nodo]]++;
    for(auto it : G[nodo]){
        if(it==ant)continue;
        dfs(it,nodo);
        if(E[nodo].size()<E[it].size()){
            swap(E[nodo],E[it]);
        }
        for(auto it2 : E[it]){
            if(v[nodo]%it2.F==0){
                if(E[nodo].find(v[nodo]/it2.F)!=E[nodo].end()){
                    res+=E[nodo][v[nodo]/it2.F]*it2.S;
                }
            }
        }
        for(auto it2 : E[it]){
            E[nodo][it2.F]+=it2.S;
        }
    }
}
signed main()
{
    jumanji
    int n,x,a,b;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    dfs(1,0);
    cout<<res<<"\n";
    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?
// https://www.hackerearth.com/submission/80416966/