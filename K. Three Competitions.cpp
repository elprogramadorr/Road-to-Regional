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
#define ii pair<int,int>
using namespace std;
const int tam=200005;
int arr[tam][5];
int C[tam];
struct ST{
	int N;
	vector<pair<int,int> > T;
	void init(int n){
		N=n;
		T.assign(4*N, {0,0});
	}
	void build(int nodo, int b, int e){
		int mid=(b+e)/2,L=nodo*2+1,R=L+1;
		if(b==e){
			T[nodo]={0,0};
			return;
		}
		build(L, b, mid);
		build(R, mid+1, e);
		if(T[L].F>T[R].F){
			T[nodo]=T[L];
		}else{
			T[nodo]=T[R];
		}
	}
	void update(int nodo, int b, int e, int pos, ii val){
		int mid=(b+e)/2,L=nodo*2+1,R=L+1;
		if(b==e){
			T[nodo]=val;
			return;
		}
		if(pos<=mid)update(L, b, mid, pos, val);
		else update(R, mid+1, e, pos, val);
		if(T[L].F>T[R].F){
			T[nodo]=T[L];
		}else{
			T[nodo]=T[R];
		}
	}
	ii query(int nodo, int b, int e, int izq, int der){
		int mid=(b+e)/2,L=nodo*2+1,R=L+1;
		if(b>=izq && e<=der)return T[nodo];
		if(der<=mid){
			return query(L, b, mid, izq, der);
		}
		if(izq>mid){
			return query(R, mid+1, e, izq, der);
		}
		ii A=query(L, b, mid, izq, der);
		ii B=query(R, mid+1, e, izq, der);
		if(A.F>B.F){
			return A;
		}else{
			return B;
		}
	}
};
ST T12,T13,T23;
bool vis[tam];
int n;
vi TOPO;
int numero=1;
void mato(int ind){
	T12.update(0,1,n,arr[ind][1],{0,0});
	T13.update(0,1,n,arr[ind][1],{0,0});
	T23.update(0,1,n,arr[ind][2],{0,0});
}
void dfs2(int nodo){
	// cout<<"entro   "<<nodo<<endl;
	if(C[nodo])return;
	C[nodo]=numero;
	//12
	
	while(true && arr[nodo][1]<n){
		ii Q=T12.query(0,1,n,arr[nodo][1]+1,n);
		if(arr[nodo][2]>Q.F)break;
		// cout<<nodo<<" pierda "<<Q.S<<endl;
		mato(Q.S);
		dfs2(Q.S);
	}
	
	//13
	while(true && arr[nodo][1]<n){
		ii Q=T13.query(0,1,n,arr[nodo][1]+1,n);
		if(arr[nodo][3]>Q.F)break;
		// cout<<nodo<<" pierda "<<Q.S<<endl;
		mato(Q.S);
		dfs2(Q.S);
	}
	//23
	while(true && arr[nodo][2]<n){
		ii Q=T23.query(0,1,n,arr[nodo][2]+1,n);
		if(arr[nodo][3]>Q.F)break;
		// cout<<nodo<<" pierda "<<Q.S<<endl;
		mato(Q.S);
		dfs2(Q.S);
	}
}

void mato2(int ind){
	T12.update(0,1,n,arr[ind][1],{-1e9,0});
	T13.update(0,1,n,arr[ind][1],{-1e9,0});
	T23.update(0,1,n,arr[ind][2],{-1e9,0});
}
void dfs1(int nodo){
	mato2(nodo);
	if(vis[nodo])return;
	vis[nodo]=true;
	//12
	while(true && arr[nodo][1]!=1){
		ii Q=T12.query(0,1,n,1,arr[nodo][1]-1);
		Q.F*=-1;
		if(arr[nodo][2]<Q.F)break;
		// cout<<nodo<<" -> "<<Q.S<<endl;
		mato2(Q.S);
		dfs1(Q.S);
	}
	//13
	while(true && arr[nodo][1]!=1){
		ii Q=T13.query(0,1,n,1,arr[nodo][1]-1);
		Q.F*=-1;
		if(arr[nodo][3]<Q.F)break;
		// cout<<nodo<<" -> "<<Q.S<<endl;
		mato2(Q.S);
		dfs1(Q.S);
	}
	//23
	while(true && arr[nodo][2]!=1){
		ii Q=T23.query(0,1,n,1,arr[nodo][2]-1);
		Q.F*=-1;
		if(arr[nodo][3]<Q.F)break;
		// cout<<nodo<<" -> "<<Q.S<<endl;
		mato2(Q.S);
		dfs1(Q.S);
	}
	TOPO.pb(nodo);
}
signed main()
{
    jumanji
	cin>>n;
	T12.init(n+1);T12.build(0,1,n);
	T13.init(n+1);T13.build(0,1,n);
	T23.init(n+1);T23.build(0,1,n);
	for(int i=1;i<=n;i++){
		for(int l=1;l<=3;l++){
			cin>>arr[i][l];
			arr[i][l]=n-arr[i][l]+1;
			// cout<<arr[i][l]<<" ";
		}
		// cout<<endl;
		T12.update(0,1,n,arr[i][1],{-arr[i][2],i});
		T13.update(0,1,n,arr[i][1],{-arr[i][3],i});
		T23.update(0,1,n,arr[i][2],{-arr[i][3],i});
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			dfs1(i);
		}
	}
	reverse(TOPO.begin(),TOPO.end());
	//esto es para la reversa

	T12.init(n+1);T12.build(0,1,n);
	T13.init(n+1);T13.build(0,1,n);
	T23.init(n+1);T23.build(0,1,n);
	for(int i=1;i<=n;i++){
		T12.update(0,1,n,arr[i][1],{arr[i][2],i});
		T13.update(0,1,n,arr[i][1],{arr[i][3],i});
		T23.update(0,1,n,arr[i][2],{arr[i][3],i});
	}
	for(int i=0;i<n;i++){
		// cout<<TOPO[i]<<endl;
		if(C[TOPO[i]]==0){
			dfs2(TOPO[i]);
			numero++;
		}	
	}
	for(int i=1;i<=n;i++){
		// cout<<i<<" = "<<C[i]<<endl;
	}
	int q,a,b;
	cin>>q;
	while(q--){
		cin>>a>>b;
		if(C[a]<=C[b]){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
    
    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?
// https://codeforces.com/gym/103371/problem/K
