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
void init(int num, int pos, vi &P, vi &A){
    //wanna generate all numbers with primes P
    if(pos==P.size()){
        if(num!=1)A.pb(num);
        return;
    }
    int curr=num;
    init(num,pos+1,P,A);
    while(curr<=1e18/P[pos]){
        curr*=P[pos];
        init(curr,pos+1,P,A);
    }
}
signed main()
{
    jumanji
    
    int n;
    cin>>n;
    vi v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    int k;
    cin>>k;
    vi P1,P2;
    for(int i=0;i<n;i++){
        if(i%2==0){
            P1.pb(v[i+1]);
        }else{
            P2.pb(v[i+1]);
        }
    }
    vi A,B;
    init(1,0,P1,A);
    init(1,0,P2,B);
    int b=1,e=1e18;
    int res=0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    // b=e=8;
    // cout<<A.size()<<" "<<B.size()<<endl;
    // return 0;
    while(b<=e){
        int mid=(b+e)/2;
        //quiero calcular la cantidad de numeros menores o iguales a mid
        int cant=0;
        int cuantos=0;

        for(int i=A.size()-1;i>=0;i--){
            if(A[i]>mid){
                continue;
            }
            while(cuantos<B.size() && A[i]<=mid/B[cuantos]){
                // cout<<A[i]<<" vs "<<B[cuantos]<<endl;
                cuantos++;
            }
            
            cant+=cuantos;
            if(A[i]<=mid){
                cant++;
            }
        }
        for(int i=0;i<B.size();i++){
            if(B[i]<=mid){
                cant++;
            }
        }
        cant++;
        // cout<<mid<<"  chimba  "<<cant<<endl;
        if(cant>=k){
            res=mid;
            e=mid-1;
        }else{
            b=mid+1;
        }
    }
    cout<<res<<"\n";

    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?
// https://codeforces.com/contest/912/problem/E