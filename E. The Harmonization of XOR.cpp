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

signed main()
{
    jumanji
    int t,n,k,x;
    int val;
    cin>>t;
    while(t--){
        cin>>n>>k>>x;//quiero xor x, quiero k subsequencias
        int XO=0;
        for(int i=1;i<=n;i++){
            XO^=i;
        }
        if(k%2==0){
            if(XO!=0){
                cout<<"NO"<<endl;
                continue;
            }
        }else{
            if(XO!=x){
                cout<<"NO"<<endl;
                continue;
            }
        }
        vector<bool>vis(n+2,false);
        vector<pair<int,int> >E;
        for(int i=1;i<=n;i++){
            if((i^x)<=n && !vis[i] && !vis[(i^x)] ){
                vis[i]=true;
                vis[i^x]=true;
                E.pb({i,i^x});
            }                
        }
        vi aux;
        for(int i=1;i<=n;i++){
            if(!vis[i])aux.pb(i);
        }
        
        if(E.size()+(aux.size()>0)<k){
            cout<<"NO"<<endl;
            continue;
        }
        
        cout<<"YES"<<endl;
        while(E.size()+(aux.size()>0)>k){
            pair<int,int> it=E.back();
            E.pop_back();
            if(it.F)aux.pb(it.F);
            if(it.S)aux.pb(it.S);
        }
        for(int i=0;i<E.size();i++){
            if(E[i].S==0){
                cout<<1<<" "<<E[i].F<<endl;
                continue;
            }
            cout<<2<<" "<<E[i].F<<" "<<E[i].S<<endl;
        }
        if(aux.size()==0)continue;
        cout<<aux.size()<<" ";
        for(int i=0;i<aux.size();i++){
            cout<<aux[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?
// https://codeforces.com/problemset/problem/1787/E