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

// size of map n -> row and m -> column
int n,m;

char mp[1001][1001];
bool vis[1001][1001];

// previousStep stores the previous direction that we moved in to arrive that this cell
int previousStep[1000][1000];

// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// this below steps are corresponding to above directions 
string stepDir = "URDL";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    
    // st will store the position of start (A) and en will store the position of end (B)
    // and always for finding the path from A to B we will use BFS
    pair<int, int> st, en;
    
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) { 
        cin>>mp[i][j];  
        vis[i][j] = false; 
        
        if(mp[i][j] == 'A') {
         st  = make_pair(i, j);   
        }
        
        if(mp[i][j] == 'B') {
            en = make_pair(i,j);
        }
    }
    }
    
    // now we will start BFS from position of A
    
    queue<pair<int, int>> q1;
    q1.push(st);
    vis[st.first][st.second] = true;
    
    while(!q1.empty()) {
         pair<int, int> temp = q1.front();
         q1.pop();
        for(int i=0;i<4;i++) {
           pair<int, int> currSquare = make_pair(temp.first + dx[i], temp.second + dy[i]);
           
           if(currSquare.first < 0 || currSquare.first >=n ||currSquare.second <0 || currSquare.second >=m ) continue;
           if(mp[currSquare.first][currSquare.second] == '#') continue;
           if(vis[currSquare.first][currSquare.second]) continue;
           
           vis[currSquare.first][currSquare.second] = true;
           previousStep[currSquare.first][currSquare.second] = i;
           q1.push(currSquare);
        }
    }
    
    
    // the end is visited means we reached end from the start 
    if(vis[en.first][en.second]) {
        cout<<"YES"<<endl;
        
        vector<int> steps;
        
        while(en != st) {
            int p = previousStep[en.first][en.second];
			steps.push_back(p);
			// p is the index of direction 
			// undo the previous step to get back to the previous square
			// Notice how we subtract dx/dy, whereas we added dx/dy before
			en = make_pair(en.first - dx[p], en.second - dy[p]);
        }
        
        // because this are from back to start 
        reverse(steps.begin(), steps.end());
        
        cout<<steps.size()<<endl;
        
        for (char c : steps) {
			cout << stepDir[c];
		}
		cout << endl;
    }
    else cout<<"NO"<<endl;

    return 0;
}