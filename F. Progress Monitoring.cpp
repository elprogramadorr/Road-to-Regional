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


const int tam=505;
int dp[tam][tam];
const int MOD=1000000007;
vi v;

int f(int izq, int der){
    // cout<<izq<<" "<<der<<endl;
    if(dp[izq][der]!=-1)return dp[izq][der];
    if(izq==der)return 1;
    dp[izq][der]=0;
    for(int i=izq+1;i<=der;i++){
        // cout<<izq+1<<" . "<<v[izq+1]<<" "<<v[i+1]<<endl;
        if(v[izq+1]<v[i+1] or i==der){

            dp[izq][der]+=f(izq+1,i)*f(i,der)%MOD;
            dp[izq][der]%=MOD;
        }
    }
    return dp[izq][der];
}
signed main()
{
    fast;
    memset(dp,-1,sizeof(dp));
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    cout<<f(0,n-1)<<endl;
        
    return 0;
}
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA YES OR YES?
// https://codeforces.com/problemset/problem/509/F