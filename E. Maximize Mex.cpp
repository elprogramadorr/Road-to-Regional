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
signed main() {
    int n,m,x;
    cin>>n>>m;
    vi p,c;
    int sink=5000*2+2;
    int sumidero=5000*2+3;
    Dinic F(5000*2+5);
    for(int i=1;i<=m;i++){
        F.add_edge(sink,i,1);
    }
    p.pb(0);c.pb(0);
    for(int i=0;i<n;i++){
        cin>>x;
        p.pb(x);
    }
    for(int i=0;i<n;i++){
        cin>>x;
        c.pb(x);
    }
    int d;
    cin>>d;
    vi k;k.pb(0);
    vector<bool>vis(n+1,false);
    for(int i=0;i<d;i++){// quienes se van
        cin>>x;
        vis[x]=true;
        k.pb(x);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            F.add_edge(c[i],p[i]+m+1,1);
        }
    }
    F.add_edge(0+m+1,sumidero,1);
    vi res;
    int ans=0;
    int acum=0;
    for(int i=d;i>=1;i--){
        while(1){
            int flujo=F.max_flow(sink,sumidero);
            if(flujo+acum==ans+1){
                ans++;
                acum+=flujo;
                F.add_edge(ans+1+m,sumidero,1);
            }else{
                break;
            }
        }   
        res.pb(ans);
        F.add_edge(c[k[i]],p[k[i]]+m+1,1);
    }
    reverse(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<"\n";
    }

    return 0;
}
// https://codeforces.com/contest/1139/problem/E