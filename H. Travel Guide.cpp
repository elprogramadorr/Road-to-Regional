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
vector<pair<int,int> >G[tam];
int dis[3][tam];
bool vis[3][tam];
void dijkstra(int nodo, int ind){
    priority_queue<pair<int,int> >q;
    q.push({0,nodo});
    dis[ind][nodo]=0;
    while(q.size()>0){
        int u=q.top().S;
        q.pop();
        if(vis[ind][u]==true){
            continue;
        }
        vis[ind][u]=true;
        for(int i=0;i<G[u].size();i++){
            int hijo=G[u][i].F;
            if(dis[ind][u]+G[u][i].S<dis[ind][hijo]){
                dis[ind][hijo]=dis[ind][u]+G[u][i].S;
                q.push({-dis[ind][hijo],hijo});
            }
        }
    }

}
void anha(){
    for(int i=0;i<3;i++){
        for(int l=0;l<tam;l++){        
            dis[i][l]=1e9;
        }
    }
}
struct ST{
    int N;
    vi T;
    void init(int n){
        N=n;
        T.assign(4*N,0);
    }
    void build(int nodo,int b, int e){
        int mid=(b+e)/2,L=2*nodo+1,R=L+1;
        if(b==e){
            T[nodo]=1e9; 
            return;
        }
        build(L,b,mid);
        build(R,mid+1,e);
        T[nodo]=min(T[L],T[R]);
    }
    void update(int nodo, int b, int e, int pos, int val){
        int mid=(b+e)/2,L=2*nodo+1,R=L+1;
        if(b==e){
            T[nodo]=min(T[nodo],val);
            return;
        }
        if(pos<=mid)update(L,b,mid,pos,val);
        else update(R,mid+1,e,pos,val);
        T[nodo]=min(T[L],T[R]);
    }
    int query(int nodo, int b, int e, int izq, int der){
        int mid=(b+e)/2,L=2*nodo+1,R=L+1;
        if(b>=izq && e<=der)return T[nodo];
        if(der<=mid)return query(L,b,mid,izq,der);
        if(izq>mid)return query(R,mid+1,e,izq,der);
        return min(query(L,b,mid,izq,der),query(R,mid+1,e,izq,der));
    }
};
signed main()
{
    jumanji
    anha();
    int n,m,a,b,w;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        G[a].pb({b,w});
        G[b].pb({a,w});
    }
    dijkstra(0,0);
    dijkstra(1,1);
    dijkstra(2,2);
    set<int>st;
    map<pair<int,pair<int,int>>,int>contar;
    ST Teta;
    // cout<<dis[0][1]<<endl;
    for(int i=0;i<n;i++){
        st.insert(dis[1][i]);
        // cout<<dis[0][i]<<" "<<dis[1][i]<<" "<<dis[2][i]<<endl;
        contar[{dis[0][i],{dis[1][i],dis[2][i]}}]++;
    }
    int num=0;
    map<int,int>ind;
    for(auto it : st){
        ind[it]=num;
        num++;
    }
    Teta.init(num);
    Teta.build(0,0,num);
    int res=0;
    for(auto it : contar){
        int a=it.F.F;
        int b=it.F.S.F;
        int c=it.F.S.S;
        //orden respecto a A
        //lave es b
        //y c es el update
        // cout<<a<<" "<<b<<" "<<c<<" = ";
        b=ind[b];
        int Q=Teta.query(0,0,num,0,b);
        // cout<<Q<<endl;
        if(Q<=c){
            //es f
        }else{
            res+=it.S;
        }
        Teta.update(0,0,num,b,c);
    }
    cout<<res<<"\n";    

    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?
// https://codeforces.com/gym/102465/problem/H