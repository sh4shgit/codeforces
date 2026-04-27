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
const int MOD = 998244353;
const int N = 2e5 + 5;

// ------------------------- Solve Function -------------------
void solve() {
    ll n, x; cin >> n >> x;
    auto cnt = [&](ll l, ll r, ll rem) -> ll {
        if (l > r) return 0;
        ll first = l + ((rem - l % 4 + 4) % 4);
        if (first > r) return 0;
        return (r - first) / 4 + 1;
    };

    ll L0 = 1 + cnt(1, x - 1, 3);
    ll L1 = cnt(1, x - 1, 1);
    ll R0 = cnt(x, n, 3);
    ll R1 = cnt(x, n, 1);
    ll ans = ((L0 % MOD) * (R0 % MOD) % MOD +(L1 % MOD) * (R1 % MOD) % MOD) % MOD;
    cout << ans << '\n';
}

// ---------------------------- Main --------------------------
int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}