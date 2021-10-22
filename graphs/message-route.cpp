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

vector<int> network[100001];
bool visited[100001];

// this below steps are corresponding to above directions
string stepDir = "URDL";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // as here we need to find the shortest route we will be using bfs only
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        network[a].push_back(b);
        network[b].push_back(a);
    }

    // need to go from 1 to 5 with shortest route

    queue<int> q1;
    q1.push(1);
    visited[1] = true;

    // vector<int> parent[100001];
    vector<ll> steps;

    map<ll, ll> m1;
    vector<int> parent;

    for (int i = 1; i <= n; i++)
        m1[i] = -1;

    while (!q1.empty())
    {
        ll temp = q1.front();
        q1.pop();

        // we got to the end
        if (temp == n)
            break;

        for (ll i = 0; i < network[temp].size(); i++)
        {
            if (!visited[network[temp][i]])
            {
                q1.push(network[temp][i]);
                visited[network[temp][i]] = true;

                //store parent infront of child
                m1[network[temp][i]] = temp;
                steps.push_back(network[temp][i]);
            }
        }
    }

    if (visited[n] == false)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        vector<int> v1;
        // ulta jana hai path par jo m1 mai saved hai
        v1.push_back(n);
        ll st = n;

        while (st != 1)
        {
            st = m1[st];
            v1.push_back(st);
        }

        cout << v1.size() << endl;
        for (ll i = v1.size() - 1; i >= 0; i--)
            cout << v1[i] << " ";
        cout << endl;
    }

    return 0;
}