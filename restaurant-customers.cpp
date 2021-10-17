#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
// wish me luck
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long mod = 1000000000 + 7;
#define loop(x, n) for (int x = 0; x < n; ++x)
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll max(ll x, ll y) { return x ^ ((x ^ y) & -(x < y)); }
ll min(ll x, ll y) { return y ^ ((x ^ y) & -(x < y)); }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
// use it for setprecision
//  cout << fixed<<setprecision(9) << min <<endl;
ll power(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        ans = ans % mod;
        a = a % mod;
        if (b & 1)
            ans = ans * a;
        b = b >> 1;
        a = a * a;
    }
    return ans;
}
void fastscan(ll &number)
{
    bool negative = false;
    register ll c;
    number = 0;
    c = getchar();
    if (c == '-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
    if (negative)
        number *= -1;
}

bool compare(pair<ll, ll> v1, pair<ll, ll> v2)
{
    return v1.first < v2.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    ll n = t;
    vector<pair<ll, ll>> v1;
    while (t--)
    {
        ll a, b;
        // cout<<"this is ip"<<endl;
        cin >> a >> b;
        v1.push_back({a, 1});
        v1.push_back({b, -1});
    }
    // cout<<" this is shit "<<t<<endl;
    ll maxv = INT_MIN;
    sort(v1.begin(), v1.end(), compare);

    // for(ll i=0;i<v1.size();i++) cout<<v1[i].first<<" "<<v1[i].second<<endl;

    ll val = 0;
    for (ll i = 0; i < 2 * n; i++)
    {
        // cout<<"chal na be "<<endl;
        // cout<<v1[i].second<<endl;
        maxv = max(maxv, val);
        val += v1[i].second;
        // cout<<" this is val "<<val<<endl;
    }

    cout << maxv << endl;

    return 0;
}