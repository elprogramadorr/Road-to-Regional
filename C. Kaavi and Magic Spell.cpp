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

const int MOD= 998244353;
const int tam=3005;
string S,T;
int dp[tam][tam];
int n,m;
//me muevo empezando de atras y tomo L's la pos de R se calcula respecto a las L's y su pos
int f(int pos, int izq){
    if(pos==-1)return 1;
    if(dp[pos][izq]!=-1)return dp[pos][izq];
    dp[pos][izq]=0;
    //pongo L
    if(izq>=m){
        dp[pos][izq]+=f(pos-1,izq+1);
        dp[pos][izq]%=MOD;
    }else{
        if(S[pos]==T[izq]){
            dp[pos][izq]+=f(pos-1,izq+1);
            dp[pos][izq]%=MOD;
        }
    }
    //pongo R
    if(izq>=m){
        dp[pos][izq]+=f(pos-1,izq);
        dp[pos][izq]%=MOD;
    }else{
        if(izq+pos>=m or S[pos]==T[pos+izq]){
            dp[pos][izq]+=f(pos-1,izq);
            dp[pos][izq]%=MOD;
        }
    }
    return dp[pos][izq];
}

signed main()
{
    memset(dp,-1,sizeof(dp));
    fast;
    cin>>S;
    cin>>T;
    n=S.size();
    m=T.size();
    int res=0;
    for(int i=m-1;i<n;i++){
        res+=f(i,0);res%=MOD;
    }
    cout<<res<<"\n";
    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN
// https://codeforces.com/contest/1336/problem/C