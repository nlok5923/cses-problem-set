#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
// wish me luck
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long mod = 1000000000+7;
#define loop(x,n) for(int x = 0; x < n; ++x)
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a % b); }
ll max(ll x, ll y){ return x ^ ((x ^ y) & -(x < y)); }
ll min(ll x, ll y){ return y ^ ((x ^ y) & -(x < y)); }
ll lcm(ll a, ll b){ return (a*b)/gcd(a, b); } 
// use it for setprecision
//  cout << fixed<<setprecision(9) << min <<endl;
ll power(ll a,ll b){ ll ans=1;while(b){ans =ans%mod;a = a%mod; if(b&1) ans = ans*a;b=b>>1;a=a*a;}return ans;}
void fastscan(ll &number) { bool negative = false; register ll c; number = 0; c = getchar(); if (c=='-') { negative = true; c = getchar(); }
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) number *= -1; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> v1[21];
    
    string s1 = "0";
    string s2 = "1";
    v1[0].push_back(s2);
    v1[0].push_back(s1);
    
    for(ll i=1;i<21;i++) {
        vector<string> temp;
        for(ll j =0;j<v1[i-1].size();j++) {
            temp.push_back(v1[i-1][j]);
        }
        
        vector<string> rev;
        
        for(ll j = v1[i-1].size()-1;j>=0;j--) {
             rev.push_back(v1[i-1][j]);
        }
        
        // jab temp push karoge tab 0 preprend karna and jab rev push karoge tab 1 preprend karna
        for(ll k=0;k<v1[i-1].size();k++) {
            v1[i].push_back("0" + temp[k]);
           
        }
        
        for(ll k =0;k<v1[i-1].size();k++) v1[i].push_back("1" + rev[k]);
    }
    
    
    ll n;
    
    cin>>n;
    ll a[n];
    ll sum = 0;
    for(ll i=0;i<n;i++) { cin>>a[i]; sum+=a[i]; }
    
    ll mind = INT_MAX;
    for(ll i=0;i<v1[n-1].size();i++) {
        ll ts = 0 ;
        
        for(ll j=0;j<v1[n-1][i].size();j++) {
            if(v1[n-1][i][j] == '1') {
                ts += a[j];
            }
        }
        
        ll val1 = ts;
        ll val2 = sum - ts;
        mind = min(abs(val2 - val1), mind);
    }
    
    cout<<mind<<endl;
    
    // for(ll i =0 ;i<v1[n-1].size();i++) cout<<v1[n-1][i]<<endl;
    
    
    return 0;
}