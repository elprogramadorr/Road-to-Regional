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

signed main()
{
    fast;
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        vi a;
        for(int i=0;i<n;i++){
            cin>>x;
            a.pb(x);
        }
        vi pref(n+2,0);
        for(int i=0;i<n;i++){
            cin>>x;
            if(a[i]<=x)continue;
            pref[a[i]]--;
            pref[x]++;
        }
        for(int i=1;i<=n;i++){
            pref[i]+=pref[i-1];
        }
        vi res;
        for(int i=1;i<=n;i++){
            bool laschicaslindassoncyanes=true;
            for(int l=i;l<=n;l+=i){
                int Q=pref[l]-pref[l-i];
                if(Q)laschicaslindassoncyanes=false;
            }
            if(laschicaslindassoncyanes)res.pb(i);
        }
        cout<<res.size()<<endl;
        for(auto it : res){
            cout<<it<<" ";
        }
        cout<<"\n";

    }
    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?
// https://codeforces.com/problemset/problem/1783/E