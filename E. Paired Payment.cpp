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
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int tam=50*100000+100005;
vector<pair<int,int> >G[tam];
int n;
void add_edge(int a, int b, int w){
    G[a].pb({b+n*w,w*w});
    for(int i=1;i<=50;i++){
        G[a+i*n].pb({b,2*i*w+w*w});
    }
}
int dis[tam];
int main()
{
    fast;
    int m,a,b,w;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        add_edge(a,b,w);
        add_edge(b,a,w);
    }
    for(int i=0;i<tam;i++){
        dis[i]=1e9;
    }
    dis[1]=0;
    priority_queue<pair<int,int> >pq;
    pq.push({0,1});
    vector<bool>vis(tam,false);
    while(!pq.empty()){
        int nodo=pq.top().S;
        pq.pop();
        if(vis[nodo])continue;
        vis[nodo]=true;
        for(auto it : G[nodo]){
            int vecino=it.F,val=it.S;
            if(dis[nodo]+val<dis[vecino]){
                dis[vecino]=dis[nodo]+val;
                pq.push({-dis[vecino],vecino});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dis[i]>=1e9){
            cout<<-1<<" ";
        }else{
            cout<<dis[i]<<" ";
        }
    }
    cout<<"\n";
    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?
// Conocerte fue un disparo al corazón
// https://codeforces.com/contest/1486/problem/E