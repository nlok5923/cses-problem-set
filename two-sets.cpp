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

        ll n; cin>>n;
        if(n%4 ==0) {
            cout<<"YES"<<endl;
            ll v1 = 1;
            ll v2 = n;
            cout<<n/2<<endl;
            for(ll i=1;i<=n/4;i++) { cout<<v1<<" "; v1++;} 
            for(ll i = 0; i< n/4;i++) { cout<<v2<<" "; v2--; } cout<<endl;
            cout<<n/2<<endl;
            while(v1 <= v2) {
                cout<<v1<<" ";
                v1++;
            }  cout<<endl;
            
        } else if(n%4==3) {
            ll val = (n-3)/4;
            cout<<"YES"<<endl;
            if(n == 3) {
                cout<<"2"<<endl;
                
                cout<<"1 2"<<endl;
                cout<<"1"<<endl;
                cout<<"3"<<endl;
            } else {
                ll v1 = 4;
                ll v2 = n;
                cout<<(n-3)/2 + 2<<endl;
                cout<<"1 2"<<" ";
                  for(ll i=1;i<=(n-3)/4;i++) { cout<<v1<<" "; v1++;}
            for(ll i = 0; i< (n-3)/4;i++) { cout<<v2<<" "; v2--; } cout<<endl;
            cout<<(n-3)/2 +1 <<endl;
            cout<<"3 ";
            while(v1 <= v2) {
                // v1++;
                cout<<v1<<" "; v1++;
            }  cout<<endl;
                
            }
    } else cout<<"NO"<<endl;
    
    
    return 0;
}