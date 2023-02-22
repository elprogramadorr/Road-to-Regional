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
const int tam=1005;
bool res[1005][1005];
void anam(int x, int y){
    res[x][y]=res[y][x]=true;
}
signed main()
{
    fast;
    int n;
    cin>>n;
    anam(2,3);
    anam(2,4);
    for(int i=2;i<=29;i++){
        int a=i*2+1,b=i*2+2;
        int va=(i-1)*2+1,vb=(i-1)*2+2;
        anam(a,va);anam(a,vb);
        anam(b,vb);anam(b,va);
    }
    
    int nuevo=90;
    for(int i=29;i>=0;i--){
        if((1<<i)&n){
            int nodo=1;
            for(int l=0;l<29-i;l++){
                anam(nodo,nuevo);
                // cout<<nodo<<" vs "<<nuevo<<endl;
                nodo=nuevo;
                nuevo++;
            }
            if(i){
                // cout<<nodo<<" "<<2*i+1<<endl;
                anam(nodo,2*i+1);
            }
            // cout<<nodo<<" "<<2*i+2<<endl;
            anam(nodo,2*i+2);
        }
    }
    cout<<1000<<endl;
    for(int i=1;i<=1000;i++){
        for(int l=1;l<=1000;l++){
            if(res[i][l]){
                cout<<'Y';
            }else{
                cout<<'N';
            }
        }
        cout<<'\n';
    }

    
    return 0;
}  
// MOL GORUYI MOLA UBI HE BEÁSE
// DUL YUNGE HANAMAN
// https://codeforces.com/contest/388/problem/B