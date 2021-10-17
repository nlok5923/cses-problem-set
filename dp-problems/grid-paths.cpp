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
    ll n;
    cin>>n;
    
    // if(n == 1) cout<<"0"<<endl;
    
    char a[n][n];
    ll dp[n][n];
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            cin>>a[i][j];
            dp[i][j] = 0;
        }
    }
    
    
    
    //define state which is no of path from dp[i][j] to dp[n-1][n-1] 
    // dp[i][j] no of path from i,j to n-1, n-1
    
    // agar vo wahi par hai tp aane ka 
    // dp[n-1][n-1] = 1; 
    // no of ways to reach i,j so
    
    // only one way to reach 0,0 
    dp[0][0] = 1;
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            
            
            if(a[i][j] == '.') {
                if(i>0) {
                     (dp[i][j] += dp[i-1][j]) %= mod;
                } 
                
                if(j>0) {
                     (dp[i][j] += dp[i][j-1]) %= mod;
                }
                
            } else {
                // yaha par gadda hai 
                dp[i][j] = 0;
            }
            
            // if(i>0) {
            //     if(a[i-1][j] == '.') {
                    // (dp[i][j] += dp[i-1][j]) %= mod;
            //     } else {
            //         dp[i][j] = 0;
            //     }
            // }
            
            // if(j>0) {
            //     if(a[i][j-1] == '.') {
            //         (dp[i][j] += dp[i][j-1]) %= mod;
            //     } else {
            //         dp[i][j] = 0;
            //     }
            // }
        }
    }
    
    cout<<dp[n-1][n-1]<<endl;
    
    return 0;
}