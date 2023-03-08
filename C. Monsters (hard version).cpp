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
const int tam=500005;
ll T[4*tam];
ll lazy[4*tam];
void init(int nodo, int b, int e){
    int L=2*nodo+1,R=L+1,mid=(b+e)/2;
    lazy[nodo]=0;
    if(e==b){
        T[nodo]=b;
        return;
    }
    init(L,b,mid);init(R,mid+1,e);
    T[nodo]=min(T[L],T[R]);
}
void update(int nodo, int b, int e, int izq, int der, ll ad){
    int L=2*nodo+1,R=L+1,mid=(b+e)/2;
    lazy[L]+=lazy[nodo];
    lazy[R]+=lazy[nodo];
    T[L]+=lazy[nodo];
    T[R]+=lazy[nodo];
    lazy[nodo]=0;
    if(b>=izq && e<=der){
        lazy[nodo]+=ad;
        T[nodo]+=ad;
        return;
    }
    if(der<=mid){
        update(L,b,mid,izq,der,ad);
        T[nodo]=min(T[L],T[R]);
        return;
    }
    if(izq>=mid+1){
        update(R,mid+1,e,izq,der,ad);
        T[nodo]=min(T[L],T[R]);
        return;
    }
    update(R,mid+1,e,izq,der,ad);
    update(L,b,mid,izq,der,ad);
    T[nodo]=min(T[L],T[R]);
}
int query(int nodo, int b, int e){
    int L=2*nodo+1,R=L+1,mid=(b+e)/2;
    if(b==e){
        if(T[nodo]<0)return b;
        return -1;
    }
    lazy[L]+=lazy[nodo];
    lazy[R]+=lazy[nodo];
    T[L]+=lazy[nodo];
    T[R]+=lazy[nodo];
    lazy[nodo]=0;
    ll res;
    if(T[L]<0){
        res=query(L,b,mid);
    }else{
        res=query(R,mid+1,e);
    }
    T[nodo]=min(T[L],T[R]);
    return res;
}
signed main()
{
    jumanji
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        vi v;
        init(0,0,n);
        for(int i=0;i<n;i++){
            cin>>x;
            v.pb(x);
        }
        int tamanio=0;
        int sum=0;
        for(int i=0;i<n;i++){
            //quiero sumar 1 a [v[i],n]
            update(0,0,n,v[i],n,-1);
            // cout<<"quiero  "<<v[i]<<" hasta "<<n<<endl;
            int pos=query(0,0,n);
            sum+=v[i];
            tamanio++;
            if(pos!=-1){
                // cout<<pos<<"  quito  "<<i<<endl;
                tamanio--;
                sum-=pos;
                update(0,0,n,pos,n,1);
            }
            //suma de 1 a n
            int sum1=(tamanio*(tamanio+1))/2;
            // if(i!=20)continue;
            cout<<sum-sum1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?
// https://codeforces.com/contest/1784/problem/C