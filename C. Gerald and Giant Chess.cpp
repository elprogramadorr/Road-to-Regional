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
const int MOD=1e9+7;
const int MAXN=2e5+5;
ll fact[MAXN];
void init(){
    fact[0]=1;
    for(int i=1;i<MAXN;i++){
        fact[i]=(fact[i-1]%MOD * i % MOD)%MOD;
    }
}
ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % MOD * x % MOD) % MOD;
        x = (x % MOD * x % MOD) % MOD;
        y >>= 1;
    }
    return res;
}
ll inv(ll a)
{
    return fpow(a, MOD - 2);
}
 
ll ncr(int n,int r){
    if(n<r){
        return 0;
    }
    ll ans=fact[n];
    ans=(ans%MOD*inv(fact[n-r])%MOD)%MOD;
    ans=(ans%MOD*inv(fact[r])%MOD)%MOD;
    return ans;
}
int yesXoryes(int x1, int y1, int x2, int y2){
    if (x1 > x2 || y1 > y2) return 0;
    int dx = x2-x1;
    int dy = y2-y1;
    return  fact[dx+dy] * inv(fact[dx]*fact[dy]%MOD) % MOD;
}
signed main()
{
    jumanji
    init();
    int h,w,n,x,y;
    cin>>h>>w>>n;
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v.pb({x,y});
    }
    v.pb({h,w});
    sort(v.begin(),v.end());
    int dp[n+3];
    for(int i=0;i<=n;i++){
        dp[i]=yesXoryes(1,1,v[i].F,v[i].S);
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<i;j++){
            if (v[j].F <= v[i].F && v[j].S <= v[i].S)
            dp[i]=(dp[i]%MOD - (dp[j]%MOD * yesXoryes(v[j].F,v[j].S,v[i].F,v[i].S)%MOD)%MOD + MOD)%MOD;
        }
    }
    cout<<dp[n]%MOD<<endl;

    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?
// https://codeforces.com/contest/560/problem/E