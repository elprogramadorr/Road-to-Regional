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
#define vi vector<int>
#define ll long long
using namespace std;
const int tam=205;
const int MOD=1e9+7;
vi v;
int dp[tam][tam][1005];
int n,k;
int f(int pos, int abiertos, int suma){
    if(suma>k)return 0;
    if(pos==n+1){
        return (abiertos==0);
    }
    int &res=dp[pos][abiertos][suma];
    if(res!=-1)return res;
    res=0;
    int nueva=suma+(v[pos]-v[pos-1])*abiertos;
    if(abiertos)res=(1LL*abiertos*f(pos+1,abiertos-1,nueva))%MOD;
    res%=MOD;
    //abro y dejo
    res+=f(pos+1,abiertos+1,nueva);res%=MOD;
    //se une
    res+=(1LL*abiertos*f(pos+1,abiertos,nueva))%MOD;res%=MOD;
    //abro y cierro
    res+=f(pos+1,abiertos,nueva);res%=MOD;
    return res;
}
int main()
{
    jumanji
    memset(dp,-1,sizeof(dp));
    int x;
    cin>>n>>k;
    v.pb(0);
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    sort(v.begin(),v.end());
    cout<<f(1,0,0)<<endl;

    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?
// su gato no le da entonces me llama y voy