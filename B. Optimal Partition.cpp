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
const int tam=500005;
int ME[5*tam];
int MA[5*tam];
int E[tam];
//two maximun query segment trees
void updateMe(int nodo, int b, int e, int pos, int val){
    int L=nodo*2+1, R=nodo*2+2, mid=(b+e)/2;
    if(b==e){
        ME[nodo]=max(ME[nodo],val);
        return;
    }
    if(pos<=mid) updateMe(L,b,mid,pos,val);
    else updateMe(R,mid+1,e,pos,val);
    ME[nodo]=ME[L];
    if(ME[R]>ME[L]) ME[nodo]=ME[R];
}
int queryME(int nodo, int b, int e, int izq, int der){
    if(izq>der)return -1e16;
    int L=nodo*2+1, R=nodo*2+2, mid=(b+e)/2;
    if(b>=izq && e<=der){
        return ME[nodo];
    }
    if(der<=mid) return queryME(L,b,mid,izq,der);
    if(izq>mid) return queryME(R,mid+1,e,izq,der);
    int p1=queryME(L,b,mid,izq,der);
    int p2=queryME(R,mid+1,e,izq,der);
    if(p1>p2) return p1;
    return p2;
}

void updateMA(int nodo, int b, int e, int pos, int val){
    int L=nodo*2+1, R=nodo*2+2, mid=(b+e)/2;
    if(b==e){
        MA[nodo]=max(MA[nodo],val);
        return;
    }
    if(pos<=mid) updateMA(L,b,mid,pos,val);
    else updateMA(R,mid+1,e,pos,val);
    MA[nodo]=MA[L];
    if(MA[R]>MA[L]) MA[nodo]=MA[R];
}

int queryMA(int nodo, int b, int e, int izq, int der){
    if(izq>der) return -1e16;
    int L=nodo*2+1, R=nodo*2+2, mid=(b+e)/2;
    if(b>=izq && e<=der){
        return MA[nodo];
    }
    if(der<=mid) return queryMA(L,b,mid,izq,der);
    if(izq>mid) return queryMA(R,mid+1,e,izq,der);
    int p1=queryMA(L,b,mid,izq,der);
    int p2=queryMA(R,mid+1,e,izq,der);
    if(p1>p2) return p1;
    return p2;
}

signed main()
{
    fast;
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        set<int>st;
        vi pref;
        st.insert(0);
        for(int i=0;i<n;i++){
            cin>>x;
            pref.pb(x);
            if(i)pref[i]+=pref[i-1];
            st.insert(pref[i]);
        }
        int num=0;
        map<int,int>ind;
        for(auto it:st){
            ind[it]=num;
            E[num]=-1e16;
            num++;
        }
        for(int i=0;i<=4*num;i++){
            ME[i]=-1e16;
            MA[i]=-1e16;
        }
        updateMA(0,0,num-1,ind[0],1);
        updateMe(0,0,num-1,ind[0],-1);
        E[ind[0]]=0;
        int dp[n];
        for(int l=1;l<=n;l++){
            int Ind=ind[pref[l-1]];
            dp[l]=l+1+queryME(0,0,num-1,0,Ind-1);
            if(l==3){
                // cout<<dp[l]<<" "<<queryME(0,0,num-1,0,Ind-1)<<endl;
            }
            dp[l]=max(dp[l],-l-1+queryMA(0,0,num-1,Ind+1,num-1));
            dp[l]=max(dp[l],E[Ind]);
            updateMA(0,0,num-1,Ind,dp[l]+(l+1));
            updateMe(0,0,num-1,Ind,dp[l]-(l+1));
            E[Ind]=max(E[Ind],dp[l]);
        }

        // cout<<dp[1]<<" "<<dp[2]<<" "<<dp[3]<<endl;
        cout<<dp[n]<<"\n";
    }
    
    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?
// https://codeforces.com/contest/1667/problem/B