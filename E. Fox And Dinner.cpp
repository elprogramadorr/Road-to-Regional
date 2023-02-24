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

const int N = 5010;
//O(V^2 * E)
//O(E * √V) para unit capacity
const long long inf = 1LL << 61;
struct Dinic {
  struct edge {
    int to, rev;
    long long flow, w;
    int id;
  };
  int n, s, t, mxid;
  vector<int> d, flow_through;
  vector<int> done;
  vector<vector<edge>> g;
  Dinic() {}
  Dinic(int _n) {
    n = _n + 10;
    mxid = 0;
    g.resize(n);
  }
  void add_edge(int u, int v, long long w, int id = -1) {
    edge a = {v, (int)g[v].size(), 0, w, id};
    edge b = {u, (int)g[u].size(), 0, 0, -2};//for bidirectional edges cap(b) = w
    g[u].emplace_back(a);
    g[v].emplace_back(b);
    mxid = max(mxid, id);
  }
  bool bfs() {
    d.assign(n, -1);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &e : g[u]) {
        int v = e.to;
        if (d[v] == -1 && e.flow < e.w) d[v] = d[u] + 1, q.push(v);
      }
    }
    return d[t] != -1;
  }
  long long dfs(int u, long long flow) {
    if (u == t) return flow;
    for (int &i = done[u]; i < (int)g[u].size(); i++) {
      edge &e = g[u][i];
      if (e.w <= e.flow) continue;
      int v = e.to;
      if (d[v] == d[u] + 1) {
        long long nw = dfs(v, min(flow, e.w - e.flow));
        if (nw > 0) {
          e.flow += nw;
          g[v][e.rev].flow -= nw;
          return nw;
        }
      }
    }
    return 0;
  }
  long long max_flow(int _s, int _t) {
    s = _s;
    t = _t;
    long long flow = 0;
    while (bfs()) {
      done.assign(n, 0);
      while (long long nw = dfs(s, inf)) flow += nw;
    }
    flow_through.assign(mxid + 10, 0);
    for(int i = 0; i < n; i++) for(auto e : g[i]) if(e.id >= 0) flow_through[e.id] = e.flow;
    return flow;
  }
};
bool is_prime(int x){
    if(x==1)return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}
const int tam = 1e5+10;
vi G2[tam];
bool vis[tam];
void dfs(int nodo, vi &v){
    vis[nodo]=true;
    v.pb(nodo);
    for(auto e:G2[nodo]){
        if(!vis[e]){
            dfs(e,v);
        }
    }
}

signed main()
{
    int n,x;
    cin>>n;
    vi v;
    v.pb(0);
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    Dinic F(n+3);
    for(int i=1;i<=n;i++){
        if(v[i]%2==0){
            F.add_edge(0,i,2);
            for(int l=1;l<=n;l++){
                if(is_prime(v[i]+v[l])){
                    F.add_edge(i,l,1);
                }
            }
        }else{
            F.add_edge(i,n+1,2);
        }
    }
    int ma=F.max_flow(0,n+1);
    if(ma!=n){
        cout<<"Impossible"<<endl;
        return 0;
    }else{
        
        for(int i=0;i<=n+1;i++){
            if(v[i]%2==0){
                for(auto e:F.g[i]){
                    if(e.flow==1){
                        G2[i].pb(e.to);
                        G2[e.to].pb(i);
                    }
                }
            }
        }
        vector<vi>res;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vi aux;
                dfs(i,aux);
                res.pb(aux);
            }
        }
        cout<<res.size()<<endl;
        for(auto e:res){
            cout<<e.size()<<" ";
            for(auto f:e){
                cout<<f<<" ";
            }
            cout<<endl;
        }


    }

    return 0;
}
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA YES OR YES?
// https://codeforces.com/contest/510/problem/E