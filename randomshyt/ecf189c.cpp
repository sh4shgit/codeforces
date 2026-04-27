#include <bits/stdc++.h>
using namespace std;

// ------------------------- Fast I/O -------------------------
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// ------------------------- Typedefs -------------------------
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// ------------------------- Macros ---------------------------
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define per(i,a,b) for (int i = (a); i > (b); --i)

// ------------------------ Debugging -------------------------
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << '\n';
#else
#define debug(x)
#endif

template<typename T> void _print(T x) { cerr << x; }
template<typename T1, typename T2> void _print(pair<T1,T2> p) {
    cerr << '{'; _print(p.ff); cerr << ", "; _print(p.ss); cerr << '}';
}
template<typename T> void _print(vector<T> v) {
    cerr << '['; for (T i : v) { _print(i); cerr << ' '; } cerr << ']';
}

// ------------------------- Constants ------------------------
const int INF = 1e9 + 5;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;  // or 998244353
const int N = 2e5 + 5;

// ------------------------- Solve Function -------------------
int vcost(char a, char b) {
    int tor = (a != 'R') + (b != 'R');
    int tob = (a != 'B') + (b != 'B');
    return min(tor, tob);
}

int hcost(char a1, char a2, char b1, char b2) {
    int topr = (a1 != 'R') + (a2 != 'R');
    int topb = (a1 != 'B') + (a2 != 'B');
    int botr = (b1 != 'R') + (b2 != 'R');
    int botb = (b1 != 'B') + (b2 != 'B');
    return min(topr, topb) + min(botr, botb);
}

void solve() {
    // your logic here
    int n; cin >> n;
    string s1,s2; cin >> s1 >> s2;
    vector<ll> dp(n + 1, 0);
    dp[0] = 0;
    dp[0] = 0;
    dp[1] = vcost(s1[0], s2[0]);
    for (int i = 2; i <= n; ++i) {
        ll v = dp[i-1] + vcost(s1[i-1], s2[i-1]);
        ll h = dp[i-2] + hcost(s1[i-2], s1[i-1], s2[i-2], s2[i-1]);
        dp[i] = min(v, h);
    }
    cout << dp[n] << '\n';

}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}