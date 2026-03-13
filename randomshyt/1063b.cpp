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
void solve() {
    int n;
    cin >> n;
    vi p(n);
    int pos_1 = -1, pos_n = -1;
    rep(i, 0, n) {
        cin >> p[i];
        if (p[i] == 1) pos_1 = i + 1; 
        if (p[i] == n) pos_n = i + 1;
    }
    string x;
    cin >> x;
    if (x[0] == '1' || x[n - 1] == '1') {
        cout << -1 << '\n';
        return;
    }
    if (x[pos_1 - 1] == '1' || x[pos_n - 1] == '1') {
        cout << -1 << '\n';
        return;
    }
    vi target_indices;
    rep(i, 1, n - 1) {
        if (x[i] == '1') {
            target_indices.pb(i);
        }
    }
    if (target_indices.empty()) {
        cout << 0 << '\n';
        return;
    }
    set<pii> ops;
    ops.insert({1, n});
    ops.insert({min(pos_1, pos_n), max(pos_1, pos_n)});
    vi s(n, 0); 
    for (auto const& op : ops) {
        int l = op.ff; 
        int r = op.ss; 
        if (r - l < 2) continue; 
        int p_l = p[l - 1]; 
        int p_r = p[r - 1]; 
        int val_min = min(p_l, p_r);
        int val_max = max(p_l, p_r);
        rep(i, l, r - 1) { 
            if (p[i] > val_min && p[i] < val_max) {
                s[i] = 1; 
            }
        }
    }

    bool possible = true;
    for (int i : target_indices) {
        if (s[i] == 0) { 
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << sz(ops) << '\n';
        for (auto const& op : ops) {
            cout << op.ff << " " << op.ss << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}