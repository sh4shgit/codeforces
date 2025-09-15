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
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

// ------------------------- Solve Function -------------------
void solve() {
    int n; cin >> n;
    vi p(n);
    vector<bool> present(n+1, false);
    vi zeros;

    rep(i,0,n) {
        cin >> p[i];
        if (p[i] == 0) zeros.pb(i);
        else present[p[i]] = true;
    }
    vi missing;
    rep(i,1,n+1) if (!present[i]) missing.pb(i);
    sort(missing.rbegin(), missing.rend());
    rep(i,0,sz(zeros)) p[zeros[i]] = missing[i];
    int l = 0;
    while (l < n && p[l] == l+1) l++;
    if (l == n) { 
        cout << 0 << "\n";
        return;
    }
    int r = n-1;
    while (r >= 0 && p[r] == r+1) r--;
    cout << r - l + 1 << "\n";
}

int main() {
    fast_io;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
