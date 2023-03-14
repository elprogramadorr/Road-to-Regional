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
struct ST{
	int N;
	vi T;
	void init(int n){
		N=n;
		T.assign(4*N, 0);
	}
	void build(int nodo, int b, int e){
		int mid=(b+e)/2,L=nodo*2+1,R=L+1;
		if(b==e){
			T[nodo]=v[b];
			return;
		}
		build(L, b, mid);
		build(R, mid+1, e);
		T[nodo]=T[L]+T[R];
	}
	void update(int nodo, int b, int e, int pos, int val){
		int mid=(b+e)/2,L=nodo*2+1,R=L+1;
		if(b==e){
			T[nodo]=val;
			return;
		}
		if(pos<=mid)update(L, b, mid, pos, val);
		else update(R, mid+1, e, pos, val);
		T[nodo]=T[L]+T[R];
	}
	int query(int nodo, int b, int e, int izq, int der){
		int mid=(b+e)/2,L=nodo*2+1,R=L+1;
		if(b>=izq && e<=der)return T[nodo];
		if(der<=mid){
			return query(L, b, mid, izq, der);
		}
		if(izq>mid){
			return query(R, mid+1, e, izq, der);
		}
		return query(L, b, mid, izq, der)+query(R, mid+1, e, izq, der);
	}
};
signed main()
{
    jumanji

    
    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?