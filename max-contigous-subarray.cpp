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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;

    cin >> n;

    ll a[n];
    ll maxa = 0, maxn = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    maxa = INT_MIN;
    for (ll i = 0; i < n; i++)
    {
        maxn += a[i];
        if (maxa < maxn)
        {
            maxa = maxn;
        }

        if (maxn < 0)
            maxn = 0;
    }

    cout << maxa << endl;

    return 0;
}