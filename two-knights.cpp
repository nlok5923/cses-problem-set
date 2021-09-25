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

ll fact(ll n);
 
ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 
// Returns factorial of n
ll fact(ll n)
{
    int res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a[10001];
    for(ll i=1;i<=1000;i++) {

        ll val = pow(i,2) * (pow(i,2) - 1);
        val = val / 2;
        a[i-1] = val;
         
    }
    
    ll diff[1001];
    
    ll val = 16;
    
    for(ll i=0;i<998;i++) {
        diff[i] = val; 
        val += 8;
    }
    
    ll actualdiff[1001];
    
    actualdiff[1] = 0;
    actualdiff[2] = 0;
    actualdiff[3] = 8;
    ll j =0 ;
    for(ll i=4;i<1000;i++) {
        actualdiff[i] = actualdiff[i-1] + diff[j];
        j++;
    }
    
        ll n; cin>>n;
        
        // for(ll i=1;i<10;i++) cout<<a[i]<<endl;
         cout << 0 << endl;
        for (long long i = 2 ; i <= n ; i++) {
            cout << (i * i) * (i * i - 1) / 2 - (4 * (i - 2) * (i - 1)) << endl;
    }
    
    return 0;
}