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
    string s; cin>>s;
    map<char, ll> m1;
    
    for(ll i=0;i<s.length();i++) m1[s[i]]++;
    
    ll oc =0 , ec = 0;
    char och;
    for(auto i: m1) {
        if(i.second % 2 !=0) { och = i.first; oc++; }
    }
    
    if(oc >1) cout<<"NO SOLUTION"<<endl;
    else {
        string sf = "";
        
        for(ll i=0;i<m1[och];i++) {
            sf += och;
        }
        
        for(auto i: m1) {
            if(i.second %2==0) {
                ll val = i.second/2;
                string s1 = ""; 
                for(ll j=0;j<val;j++) 
                s1 += i.first;
                
                sf  = s1 + sf + s1;
            }
        }
        
        cout<<sf<<endl;
        
    }
    
    return 0;
}