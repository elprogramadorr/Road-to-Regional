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
const int tam=30005;
int dp[tam][605];
int d;
int vis[tam];
int medio=300;
int f(int pos, int suma){
    int dif=suma-300;
    // if(pos<=100){
    //     cout<<dif<<"  pos "<<pos<<endl;
    // }
    if(pos>=tam){
        return 0;
    }
    if(dp[pos][suma]!=-1){
        return dp[pos][suma];
    }
    dp[pos][suma]=0;
    for(int i=-1;i<=1;i++){
        int nuevo=i+dif+d;
        // if(pos<=100){
        //     cout<<"psos "<<nuevo<<endl;
        // }
        if(nuevo<=0)continue;
        dp[pos][suma]=max(dp[pos][suma],vis[pos]+f(pos+nuevo,suma+i));
    }
    return dp[pos][suma]; 
}
signed main()
{
    jumanji
    int n,x;
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>x;
        vis[x]++;
    }
    memset(dp,-1,sizeof(dp));
    cout<<f(d,300)<<endl;
    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?
// https://codeforces.com/contest/505/problem/C