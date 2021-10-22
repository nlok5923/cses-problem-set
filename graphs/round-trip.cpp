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

// this below steps are corresponding to above directions
string stepDir = "URDL";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;

    vector<int> v1[n + 1];

    for (ll i = 0; i < m; i++)
    {
        ll c1, c2;
        cin >> c1 >> c2;
        v1[c1].push_back(c2);
        v1[c2].push_back(c1);
    }

    // let's try with
    ll f = 0;
    // trying all cities one by one
    for (ll j = 1; j <= n; j++)
    {

        map<ll, bool> visited;

        // memset(visited, false, sizeof(visited));

        queue<int> q1;
        q1.push(j);
        // cout<<" this is start "<<j<<endl;
        visited[j] = true;

        vector<int> yatra;

        yatra.push_back(j);
        ll k = 0;
        while (!q1.empty())
        {
            ll ele = q1.front();
            q1.pop();
            k++;
            if (ele == j && k != 1)
            {
                yatra.push_back(ele);
                break;
            }

            for (ll i = 0; i < v1[ele].size(); i++)
            {

                if (visited[v1[ele][i]] != true)
                {
                    yatra.push_back(v1[ele][i]);
                    // cout<<"andar aaya mai "<<
                    visited[v1[ele][i]] = true;

                    q1.push(v1[ele][i]);
                }
            }
        }

        // cout<<" this is yatra "<<yatra.size()<<endl;
        if (yatra.size() >= 2)
        {
            f = 1;
            cout << yatra.size() << endl;
            for (ll k = 0; k < yatra.size(); k++)
                cout << yatra[k] << " ";
            cout << endl;
        }
    }

    if (f == 0)
        cout << "IMPOSSIBLE" << endl;

    return 0;
}