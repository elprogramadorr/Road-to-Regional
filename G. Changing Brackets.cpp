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
    int t,q,n,izq,der;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        int n=s.size();
        vi pref(n+2,0);
        vi pref2(n+2,0);
        for(int i=0;i<n;i++){
            if(s[i]=='[' or s[i]==']'){
                if(i&1){
                    pref[i]++;
                }else{
                    pref2[i]++;
                }
            }
        }
        for(int i=1;i<n;i++){
            pref[i]+=pref[i-1];
            pref2[i]+=pref2[i-1];
        }
        cin>>q;
        while(q--){
            cin>>izq>>der;
            izq--;der--;
            int A=pref[der];
            if(izq)A-=pref[izq-1];

            int B=pref2[der];
            if(izq)B-=pref2[izq-1];
            cout<<abs(A-B)<<endl;
        }
    }
    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN GOLA Yes or Yes?
// https://codeforces.com/problemset/problem/1593/G