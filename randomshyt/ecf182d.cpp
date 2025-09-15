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
const int N = 2e5 + 5;

// ------------------------- Solve Function -------------------
void solve() {
    int n; ll y;
    cin >> n >> y;
    vi price(n);
    int maxC = 0;
    rep(i,0,n) {
        cin >> price[i];
        maxC = max(maxC, price[i]);
    }

    // freq of original prices
    vi freq(maxC + 1, 0);
    rep(i,0,n) freq[price[i]]++;

    // prefix sums for range queries
    vi pref(maxC + 1, 0);
    rep(i,1,maxC+1) pref[i] = pref[i-1] + freq[i];

    ll best = LLONG_MIN;
    ll base = y * 1LL * n;

    for (int x = 2; x <= maxC + 1; ++x) {
        int vmax = (maxC + x - 1) / x; // ceil(maxC/x)
        ll sumNew = 0;
        ll reused = 0;
        for (int v = 1; v <= vmax; ++v) {
            int L = (v - 1) * x + 1;
            int R = min(v * x, maxC);
            if (L > maxC) break;
            int cnt = pref[R] - pref[L - 1];
            if (cnt == 0) continue;
            sumNew += 1LL * v * cnt;
            int have = (v <= maxC ? freq[v] : 0);
            reused += min<ll>(cnt, have);
        }
        ll total = sumNew + y * reused - base;
        best = max(best, total);
    }

    cout << best << '\n';
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
