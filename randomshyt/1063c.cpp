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
// Use a large enough value for infinity
const int INF = 2e9 + 7; 
const ll LINF = 1e18;
const int MOD = 1e9 + 7;  // or 998244353
const int N = 2e5 + 5; 

// ------------------------- Solve Function -------------------
void solve() {
    int n;
    cin >> n;
    int max_val = 2 * n; 
    vector<vi> a(2, vi(n));
    rep(i, 0, 2) {
        rep(j, 0, n) {
            cin >> a[i][j];
        }
    }

    vi pref_min1(n), pref_max1(n);
    vi suff_min2(n), suff_max2(n);

    pref_min1[0] = a[0][0];
    pref_max1[0] = a[0][0];
    rep(j, 1, n) {
        pref_min1[j] = min(pref_min1[j - 1], a[0][j]);
        pref_max1[j] = max(pref_max1[j - 1], a[0][j]);
    }

    suff_min2[n - 1] = a[1][n - 1];
    suff_max2[n - 1] = a[1][n - 1];
    for (int j = n - 2; j >= 0; --j) {
        suff_min2[j] = min(suff_min2[j + 1], a[1][j]);
        suff_max2[j] = max(suff_max2[j + 1], a[1][j]);
    }

    vi m(n), M(n);
    int max_l_possible = 0; 
    rep(j, 0, n) {
        m[j] = min(pref_min1[j], suff_min2[j]);
        M[j] = max(pref_max1[j], suff_max2[j]);
        max_l_possible = max(max_l_possible, m[j]);
    }

    
    vi min_M_at_m(max_val + 2, INF);
    rep(j, 0, n) {
        min_M_at_m[m[j]] = min(min_M_at_m[m[j]], M[j]);
    }

    
    vi suffix_min_M(max_val + 2, INF);
    for (int l = max_val; l >= 1; --l) {
        suffix_min_M[l] = min(suffix_min_M[l + 1], min_M_at_m[l]);
    }

    ll ans = 0;

    rep(l, 1, max_l_possible + 1) {
        int r_min_for_l = suffix_min_M[l];
        int r_start = max(l, r_min_for_l);
        if (r_start <= max_val) {
            ans += (max_val - r_start + 1);
        }
    }
    cout << ans << '\n';
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}