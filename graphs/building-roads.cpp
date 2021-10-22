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

// 0 = up, 1 = right, 2 = down, 3 = left
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

bool visited[100001];
vector<int> country[100001];

// this below steps are corresponding to above directions
string stepDir = "URDL";

void dfs(ll i)
{
    visited[i] = true;

    // cout<<" this is i "<<i<<" it's size "<<country[i].size()<<endl;

    for (ll j = 0; j < country[i].size(); j++)
    {
        if (!visited[country[i][j]])
        {
            // cout<<"this is not visited "<<country[i][j]<<endl;
            dfs(country[i][j]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m, n;
    // n->cities and m-> roads
    cin >> n >> m;

    for (ll i = 0; i < m; i++)
    {
        ll c1, c2;
        cin >> c1 >> c2;
        country[c1].push_back(c2);
        country[c2].push_back(c1);
    }

    vector<ll> v1;

    for (ll i = 1; i <= n; i++)
    {
        //agar vo visited nahi hai means we got a element of unconnected component
        if (!visited[i])
        {
            //   cout<<" this is called "<<endl;
            v1.push_back(i);
            dfs(i);
        }
    }

    cout << v1.size() - 1 << endl;
    // cout<<v1[0]<<endl;

    for (ll i = 0; i < v1.size() - 1; i++)
    {
        cout << v1[i] << " " << v1[i + 1] << endl;
    }

    return 0;
}